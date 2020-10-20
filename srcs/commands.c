/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 10:44:20 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 19:11:04 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_bash_command(char *true_path, char **cmd,
								t_list **env, int is_path)
{
	int	pid;
	int	status;

	errno = 0;
	g_status = 0;
	pid = fork();
	if (pid == -1)
		ft_error_errno_exit();
	if (pid == 0)
	{
		if (execve(true_path, cmd, env_to_strstr(*env)) == -1)
			ft_error_errno_exit();
	}
	else
	{
		if (!is_path)
			free(true_path);
		wait(&status);
		set_status(status);
	}
}

void	run_command(char **cmd, t_list **env, t_fd *fd_pipe)
{
	char	*true_path;
	int		is_path;
	int		flg;

	errno = 0;
	is_path = 0;
	flg = 0;
	if (check_builtins(cmd, env, fd_pipe))
		return ;
	else if ((is_path = is_it_path(cmd, &true_path)) < 0)
		return ;
	else if (is_path == 1)
		;
	else if (!(true_path = parse_path(cmd, *env, &flg)))
	{
		(flg == 1) ? error_cmd_not_found(cmd[0]) : error_no_file_or_dir(cmd[0]);
		return ;
	}
	exec_bash_command(true_path, cmd, env, is_path);
	if (fd_pipe->was_fork == 1)
		fd_pipe->was_fork = 0;
}

void	my_fork(char **cmd, t_list **env, t_fd *fd_pipe)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error_errno_exit();
	if (pid == 0)
	{
		dup2(fd_pipe->stdout_write, STDOUT_FILENO);
		run_command(cmd, env, fd_pipe);
		close(fd_pipe->stdin_read);
		close(fd_pipe->stdout_write);
		close(STDOUT_FILENO);
		exit(0); 
	}
	else
	{
		dup2(fd_pipe->stdin_read, STDIN_FILENO);
		close(fd_pipe->stdout_write);
		wait(NULL);
		close(fd_pipe->stdin_read);
		if (fd_pipe->was_redir)
			fd_pipe->was_redir = 0;
		fd_pipe->back_redir = 0;
		fd_pipe->needed_fork = 0;
		fd_pipe->was_fork = 1;
	}
}
