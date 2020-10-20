/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:09:24 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/17 17:25:15 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_echo(char **cmd, char *strlowcase)
{
	int i;

	if (ft_strstrlen(cmd) == 1)
		ft_putendl_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(cmd[1], "-n"))
	{
		i = 2;
		while (cmd[i])
		{
			ft_putstr_fd(cmd[i++], STDOUT_FILENO);
			(cmd[i]) ? ft_putstr_fd(" ", STDOUT_FILENO) : 1 - 1;
		}
	}
	else
	{
		i = 1;
		while (cmd[i])
		{
			ft_putstr_fd(cmd[i++], STDOUT_FILENO);
			(cmd[i]) ? ft_putstr_fd(" ", STDOUT_FILENO) : 1 - 1;
		}
		ft_putendl_fd("", STDOUT_FILENO);
	}
	free(strlowcase);
	return (1);
}
