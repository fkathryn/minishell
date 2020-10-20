/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:05:58 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 11:22:58 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_back_redir_file_utils(char *file_name)
{
	free(file_name);
	g_status = 1;
	g_redir_error = 1;
	return (0);
}

int	check_back_redir_file(char **cmd, char *file_name)
{
	int			stat_res;
	struct stat	file_stat;

	stat_res = stat(file_name, &file_stat);
	if (stat_res == -1)
	{
		error_no_file_or_dir(file_name);
		return (check_back_redir_file_utils(file_name));
	}
	else if (S_ISDIR(file_stat.st_mode))
	{
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putendl_fd(STDIN_IS_A_DIR, STDERR_FILENO);
		return (check_back_redir_file_utils(file_name));
	}
	else if (!(file_stat.st_mode & S_IRUSR))
	{
		error_perm_denied(file_name);
		return (check_back_redir_file_utils(file_name));
	}
	return (1);
}
