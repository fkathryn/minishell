/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:40:34 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/17 15:47:10 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dir(char *file)
{
	int			stat_res;
	struct stat	file_stat;

	if (!ft_strcmp(file, ""))
		return (0);
	if ((stat_res = stat(file, &file_stat) == -1))
	{
		error_no_file_or_dir(file);
		g_status = 1;
		return (0);
	}
	else if (!S_ISDIR(file_stat.st_mode))
	{
		error_not_a_dir(file);
		return (0);
	}
	return (1);
}
