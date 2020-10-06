/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 10:44:20 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/06 12:40:31 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(char *path, char **cmd)
{
	char	*full_path;
	char	*cmd_name;
	int		fd;

	if (!(cmd_name = ft_strjoin("/", cmd[0])))
		return (NULL);
	if (!(full_path = ft_strjoin(path, cmd_name)))
	{
		free (cmd_name);
		return (NULL);
	}
	if ((fd = open(full_path, O_RDONLY)) != -1)
	{
		close(fd);
		free(cmd_name);
		return (full_path);
	}
	free(full_path);
	free(cmd_name);
	return (NULL);
}

char	*parse_path(char **cmd, t_list *env)
{
	t_list	*tmp;
	char	**splitted_path;
	int		i;
	char	*true_path;

	if (!env)
		return (NULL);
	tmp = env;
	while (tmp)
	{
		if ((t_env*)tmp->content && !ft_strcmp(((t_env*)tmp->content)->name, "PATH"))
		{
			splitted_path = ft_split(((t_env*)tmp->content)->value, ':');
			i = 0;
			while (splitted_path[i])
			{
				if ((true_path = check_path(splitted_path[i++], cmd)))
				{
					ft_free_strstr(splitted_path);
					return (true_path);
				}
			}
			ft_free_strstr(splitted_path);
			break ;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	run_command(char *line, char **cmd, t_list **env)
{
	int		pid;
	int		fd;
	char	*true_path;

	errno = 0;
	if (check_builtins(line, cmd, env))
        return ;
	if ((fd = open(cmd[0], O_RDONLY)) != -1)
		true_path = cmd[0];
	else if (!(true_path = parse_path(cmd, *env)))
	{
		ft_putstr_fd(SHELL, STDERR_FILENO);
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putendl_fd(CMD_NOT_FOUND, STDERR_FILENO);
	}
	pid = fork();
	if (pid == -1)
		my_exit(line, cmd, *env); // с каким значением?
	if (pid == 0)
	{
		if (execve(true_path, cmd, NULL) == -1)
			my_exit(line, cmd, *env); // с каким значением?
	}
	else
	{
		if (fd == -1)
			free(true_path);
		else
			close(fd);
		wait(NULL);
	}
}
