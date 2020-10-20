/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:38:31 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 12:53:26 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_exit2(char **cmd, t_fd *fd_pipe, size_t len)
{
	if (fd_pipe->was_fork == 1)
	{
		if (len == 1)
			g_status = 0;
		else if (len == 2)
		{
			if (ft_str_is_num(cmd[1]))
				g_status = ft_atoi(cmd[1]);
			else
				error_num_arg_required(cmd[1], 1);
		}
		else if (len > 2)
		{
			if (ft_str_is_num(cmd[1]))
				error_exit_many_args();
			else
				error_num_arg_required(cmd[1], 1);
		}
	}
	return (1);
}

int	my_exit(char **cmd, t_fd *fd_pipe)
{
	size_t	len;

	len = ft_strstrlen(cmd);
	if (fd_pipe->was_fork == 0)
	{
		ft_putendl_fd("exit", STDERR_FILENO);
		if (len == 1)
			exit(g_status);
		else if (len == 2)
		{
			if (ft_str_is_num(cmd[1]))
				exit(ft_atoi(cmd[1]));
			else
				error_num_arg_required(cmd[1], 255);
		}
		else if (len > 2)
		{
			if (ft_str_is_num(cmd[1]))
				error_exit_many_args();
			else
				error_num_arg_required(cmd[1], 255);
		}
	}
	return (my_exit2(cmd, fd_pipe, len));
}
