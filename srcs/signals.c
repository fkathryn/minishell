/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:02:46 by fkathryn          #+#    #+#             */
/*   Updated: 2020/10/17 15:34:16 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_no_usinput(void)
{
	ft_putendl_fd("\nexit", 1);
	exit(0);
}

void	ft_sigint(int sig)
{
	int		pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_status = 1;
		if (pid)
			write_prompt();
	}
}

void	ft_quit(int sig)
{
	int		pid;
	int		status;

	(void)sig;
	pid = waitpid(-1, &status, WNOHANG);
	if (!pid)
		ft_putendl_fd("Quit: 3", 1);
	else
		ft_putstr_fd("\b\b  \b\b", 1);
}
