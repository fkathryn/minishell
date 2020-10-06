/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:09:24 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/05 09:28:20 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_echo(char **cmd, t_list *env)
{
	int i;

	(void)env;
	if (!ft_strcmp(cmd[1], "-n"))
	{
		i = 2;
		while (cmd[i])
		{
			ft_putstr_fd(cmd[i++], STDOUT_FILENO);
			if (cmd[i])
				ft_putstr_fd(" ", STDOUT_FILENO);
		}
	}
	else
	{
		i = 1;
		while (cmd[i])
		{
			ft_putstr_fd(cmd[i++], STDOUT_FILENO);
			if (cmd[i])
				ft_putstr_fd(" ", STDOUT_FILENO);
		}
		ft_putendl_fd("", STDOUT_FILENO);
	}
	return (1);
}
