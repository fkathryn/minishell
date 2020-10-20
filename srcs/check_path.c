/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:01:28 by fkathryn          #+#    #+#             */
/*   Updated: 2020/10/17 17:23:42 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(char *path, char **cmd)
{
	char	*full_path;
	char	*cmd_name;
	int		fd;

	if (!(cmd_name = ft_strjoin("/", cmd[0])))
		ft_error_errno_exit();
	if (!(full_path = ft_strjoin(path, cmd_name)))
	{
		free(cmd_name);
		ft_error_errno_exit();
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

char	*parse_path2(char **splitted_path, char **cmd)
{
	char	*true_path;
	int		i;

	i = 0;
	while (splitted_path[i])
	{
		if ((true_path = check_path(splitted_path[i++], cmd)))
		{
			ft_free_strstr(splitted_path);
			return (true_path);
		}
	}
	return (NULL);
}

char	*parse_path(char **cmd, t_list *env, int *flag)
{
	t_list	*tmp;
	char	**splitted_path;
	char	*true_path;

	if (!env)
		return (NULL);
	tmp = env;
	while (tmp)
	{
		if ((t_env*)tmp->content &&
			!ft_strcmp(((t_env*)tmp->content)->name, "PATH"))
		{
			*flag = 1;
			splitted_path = ft_split(((t_env*)tmp->content)->value, ':');
			if ((true_path = parse_path2(splitted_path, cmd)))
				return (true_path);
			ft_free_strstr(splitted_path);
			break ;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int		check_errors(int stat_res, char **cmd, struct stat file_stat)
{
	if (stat_res == -1)
	{
		error_no_file_or_dir(cmd[0]);
		return (0);
	}
	else if (S_ISDIR(file_stat.st_mode))
	{
		error_is_a_dir(cmd[0]);
		return (0);
	}
	else if (!(file_stat.st_mode & S_IXUSR))
	{
		error_perm_denied(cmd[0]);
		return (0);
	}
	return (1);
}

int		is_it_path(char **cmd, char **true_path)
{
	int			stat_res;
	struct stat	file_stat;
	int			three_points;

	g_status = 0;
	three_points = ft_strncmp("../", cmd[0], 3);
	if (!three_points || !ft_strncmp("./", cmd[0], 2) || cmd[0][0] == '/')
	{
		if (!three_points || cmd[0][0] == '/')
		{
			stat_res = stat(cmd[0], &file_stat);
			three_points = 0;
		}
		else
		{
			stat_res = stat(cmd[0], &file_stat);
			three_points = 2;
		}
		if (!check_errors(stat_res, cmd, file_stat))
			return (-1);
		*true_path = &cmd[0][three_points];
		return (1);
	}
	return (0);
}
