/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:01:14 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/06 12:40:10 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_home(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(((t_env*)tmp->content)->name, "HOME"))
			return (((t_env*)tmp->content)->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	cd_error(char **cmd)
{
	ft_putstr_fd(SHELL, STDERR_FILENO);
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(cmd[1], STDERR_FILENO);
	ft_putendl_fd(": No such file or directory", STDERR_FILENO);
}

int		my_cd(char **cmd, t_list *env)
{
	char	*home_value;

	(void)env;
	if (ft_strstrlen(cmd) == 1)
	{
		if (!(home_value = find_home(env)))
		{
			ft_putstr_fd(SHELL, STDERR_FILENO);
			ft_putstr_fd("cd: ", STDERR_FILENO);
			ft_putstr_fd("HOME", STDERR_FILENO);
			ft_putendl_fd(" not set", STDERR_FILENO);
		}
		if (chdir(home_value) == 0)
			;
		else
			cd_error(cmd);
	}
	else
	{
		if (chdir(cmd[1]) == 0)
			;
		else
			cd_error(cmd);
	}
	return (1);
}
