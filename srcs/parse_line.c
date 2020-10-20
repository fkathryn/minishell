/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:02:30 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 19:15:20 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	ft_add_cmd(char *str, int *i, char ***cmd)
{
	if (str[0] == '\0' && !g_flag)
	{
		(*cmd) = ft_strstr_realloc((*cmd), 1);
		(*cmd)[(*i)++] = str;
	}
	else if (str[0] != '\0')
	{
		(*cmd) = ft_strstr_realloc((*cmd), 1);
		(*cmd)[(*i)++] = str;
	}
	else
		free(str);
}

int				find_pipe_or_redir(char **line, t_fd *fd_pipe, \
	t_list *env, char **cmd)
{
	if (**line == '|' && fd_pipe->was_redir == 0)
	{
		fd_pipe->needed_fork = 1;
		get_pipe_fd(line, fd_pipe);
		return (1);
	}
	else if (**line == '|' && fd_pipe->was_redir == 1)
		return (1);
	else if (**line == '>')
	{
		fd_pipe->needed_fork = 1;
		get_pipe_fd(line, fd_pipe);
		(*line)--;
		get_redir_fd(line, fd_pipe, env, cmd);
		g_flag_redir = 1;
	}
	else if (**line == '<')
	{
		// fd_pipe->back_redirect = 0;
		get_redir_fd(line, fd_pipe, env, cmd);
		dup2(fd_pipe->stdin_read, STDIN_FILENO);
		// dup2(fd_pipe->stdout_write, STDOUT_FILENO);
	}
	return (0);
}

void			get_empty_pipe(char **line, t_fd *fd_pipe)
{
	int		fd[2];

	close(fd_pipe->stdin_read);
	close(fd_pipe->stdout_write);
	close(STDIN_FILENO);
	close(g_fd);
	(*line)++;
	if (pipe(fd) == -1)
		ft_error_errno_exit();
	close(fd[1]);
	fd_pipe->stdin_read = fd[0];
	dup2(fd_pipe->stdin_read, STDIN_FILENO);
	fd_pipe->needed_fork = 0;
}

char			**parse_line(char **line, t_fd *fd_pipe, t_list *env)
{
	char	*str;
	char	**cmd;
	int		i;

	cmd = NULL;
	str = NULL;
	i = 0;
	g_flag_redir = 0;
	while (**line)
	{
		while (ft_isspace(**line))
			(*line)++;
		if (!**line || (**line && **line == ';') || \
		(**line == '|' && g_flag_redir))
			break ;
		else if (**line == '|' && !cmd)
			get_empty_pipe(line, fd_pipe);
		else if ((find_pipe_or_redir(line, fd_pipe, env, cmd)))
			break ;
		else if (g_redir_error == 1)
			break ;
		if ((str = parse_argument(line, env)))
			ft_add_cmd(str, &i, &cmd);
	}
	return (cmd);
}
