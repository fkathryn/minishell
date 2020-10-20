/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 09:57:58 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 12:37:30 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_from_errno(char *param)
{
	ft_putstr_fd(SHELL, STDERR_FILENO);
	ft_putstr_fd(param, STDERR_FILENO);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	g_status = 1;
}

void	error_not_a_dir(char *param)
{
	ft_putstr_fd(SHELL, STDERR_FILENO);
	ft_putstr_fd(param, STDERR_FILENO);
	ft_putendl_fd(NOT_A_DIR, STDERR_FILENO);
	g_status = 1;
}

int		error_home_not_set(void)
{
	ft_putstr_fd(SHELL, STDERR_FILENO);
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd("HOME", STDERR_FILENO);
	ft_putendl_fd(" not set", STDERR_FILENO);
	g_status = 1;
	return (1);
}

void	error_num_arg_required(char *param, int num)
{
	ft_putstr_fd(SHELL_EXIT, STDERR_FILENO);
	ft_putstr_fd(param, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	if (num == 255)
		exit(255);
	else
		g_status = 1;
}

void	error_syntax_unexpected_token(void)
{
	ft_putendl_fd("minishell: syntax error near unexpected token `newline\'", \
	STDOUT_FILENO);
	g_status = 258;
	g_redir_error = 1;
}
