/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:31:56 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 19:24:15 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			get_pipe_fd(char **line, t_fd *fd_pipe)
{
	int fd[2];

	(*line)++;
	if (pipe(fd) == -1)
		ft_error_errno_exit();
	fd_pipe->stdin_read = fd[0];
	fd_pipe->stdout_write = fd[1];
}

void			double_redir(char **line, t_fd *fd_pipe, t_list *env)
{
	char	*file_name;

	if (g_fd != 0)
		close(g_fd);
	(*line) += 2;
	if (!check_redirs(line))
		return ;
	while (ft_isspace(**line))
		(*line)++;
	if (!(file_name = parse_argument(line, env)))
	{
		error_syntax_unexpected_token();
		return ;
	}
	if ((g_fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
	{
		error_from_errno(file_name);
		free(file_name);
		g_redir_error = 1;
		return ;
	}
	free(file_name);
	// if (fd_pipe->stdout_write >= 0)
		fd_pipe->stdout_write = g_fd;
}

void			forward_redir(char **line, t_fd *fd_pipe, t_list *env)
{
	char *file_name;

	if (g_fd != 0)
		close(g_fd); // Здесь закрывается фд для чтения из бэкредира
	(*line)++;
	if (!check_redirs(line))
		return ;
	while (ft_isspace(**line))
		(*line)++;
	if (!(file_name = parse_argument(line, env)))
	{
		error_syntax_unexpected_token();
		return ;
	}
	if ((g_fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	{
		error_from_errno(file_name);
		free(file_name);
		g_redir_error = 1;
		return ;
	}
	free(file_name);
	// if (fd_pipe->stdout_write >= 0)
		fd_pipe->stdout_write = g_fd;
}

void			back_redir(char **line, t_fd *fd_pipe, t_list *env, char **cmd)
{
	char		*file_name;

	if (g_fd != 0)
		close(g_fd);
	(*line)++;
	if (!check_back_redirs(line))
		return ;
	while (ft_isspace(**line))
		(*line)++;
	if (!(file_name = parse_argument(line, env)))
	{
		error_syntax_unexpected_token();
		return ;
	}
	if (!check_back_redir_file(cmd, file_name))
		return ;
	if ((g_fd = open(file_name, O_RDONLY, 0644)) == -1)
	{
		error_from_errno(file_name);
		free(file_name);
		g_redir_error = 1;
		return ;
	}
	if (fd_pipe->stdin_read >= 0)
		fd_pipe->stdin_read = g_fd;
	g_fd = 0; // костыль чтобы не закрывался фд в форвард_редир
}

void			get_redir_fd(char **line, t_fd *fd_pipe, t_list *env, \
															char **cmd)
{
	while (ft_isspace(**line))
		(*line)++;
	if (!(ft_strncmp(*line, ">>", 2)))
	{
		fd_pipe->was_redir = 1;
		double_redir(line, fd_pipe, env);
	}
	else if (!(ft_strncmp(*line, ">", 1)))
	{
		fd_pipe->was_redir = 1;
		forward_redir(line, fd_pipe, env);
	}
	else if (!(ft_strncmp(*line, "<", 1)))
	{
		fd_pipe->back_redir = 1;
		back_redir(line, fd_pipe, env, cmd);
	}
}
