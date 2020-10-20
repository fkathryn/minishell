/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 10:44:46 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 12:55:29 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_prompt(void)
{
	char	*path;

	ft_putstr_fd(GREEN, STDOUT_FILENO);
	ft_putstr_fd("minishell:~", STDOUT_FILENO);
	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putstr_fd(DEFAULT, STDOUT_FILENO);
	free(path);
}

void	prepare_program(int ac, char **av, t_list **env, char **ev)
{
	(void)ac;
	(void)av;
	*env = NULL;
	g_status = 0;
	dup2(STDOUT_FILENO, 3);
	dup2(STDIN_FILENO, 4);
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, ft_quit);
	ft_lstadd_back(env, ft_lstnew(NULL));
	init_env(env, ev);
	ft_putstr_fd(CLEAN, STDOUT_FILENO);
}

void	settings_after_separator(t_fd *fd_pipe, char **line)
{
	if (g_fd != 0)
		close(g_fd);
	g_fd = 0;
	g_redir_error = 0;
	fd_pipe->was_redir = 0;
	fd_pipe->was_fork = 0;
	fd_pipe->needed_fork = 0;
	dup2(4, 0);
	(*line)++;
}

void	set_status(int status)
{
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_status = WTERMSIG(status) + 128;
}
