/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:49:25 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 12:51:11 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_exit_many_args(void)
{
	ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
	g_status = 1;
}
