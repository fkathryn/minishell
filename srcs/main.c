/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:32:42 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 13:47:20 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_line(int fd)
{
	char *res;
	char *tmp;
	char buff[2];

	buff[1] = 0;
	res = NULL;
	while (1)
	{
		tmp = res;
		if (read(fd, buff, 1) == 0)
		{
			if (!tmp)
				break ;
			continue ;
		}
		if (!(res = ft_strjoin((res ? res : ""), (*buff == '\n' ? "" : buff))))
			ft_error_errno_exit();
		if (tmp)
			free(tmp);
		if (*buff == '\n')
			break ;
	}
	return (res);
}

int		compile_cmd(char *line, t_fd *fd_pipe, t_list **env, char **cmd)
{
	if (g_redir_error == 1)
	{
		if (cmd)
			ft_free_strstr(cmd);
		return (0);
	}
	if (*line == ';' && *(line + 1) == ';')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;;\'", 3);
		g_status = 258;
		if (cmd)
			ft_free_strstr(cmd);
		return (0);
	}
	if (cmd)
	{
		if (fd_pipe->needed_fork == 1)
			my_fork(cmd, env, fd_pipe);
		else
			run_command(cmd, env, fd_pipe);
		ft_free_strstr(cmd);
	}
	else
		g_status = 0;
	return (1);
}

void	minishell(char *line, t_list **env)
{
	char	**cmd;
	t_fd	fd_pipe;

	if (!check_dir_in_begin(&line))
		return ;
	fd_pipe.was_redir = 0;
	fd_pipe.was_fork = 0;
	fd_pipe.needed_fork = 0;
	g_fd = 0;
	while (*line)
	{
		if (*line == ';')
			settings_after_separator(&fd_pipe, &line);
		else
		{
			cmd = parse_line(&line, &fd_pipe, *env);
			if (!compile_cmd(line, &fd_pipe, env, cmd))
				return ;
		}
	}
}

int		main(int ac, char **av, char **ev)
{
	t_list	*env;
	char	*user_input;

	prepare_program(ac, av, &env, ev);
	while (1)
	{
		dup2(4, STDIN_FILENO);
		write_prompt();
		g_redir_error = 0;
		if (!(user_input = read_line(STDOUT_FILENO)))
			ft_no_usinput();
		else
			minishell(user_input, &env);
		free(user_input);
	}
	free_env(env);
	return (0);
}
