/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 14:33:56 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/06 11:54:49 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		variable_error(char **cmd, int i)
{
	ft_putstr_fd(SHELL, STDERR_FILENO);
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putstr_fd(": \'", STDERR_FILENO);
	ft_putstr_fd(cmd[i], STDERR_FILENO);
	ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
	return (0);
}

int		check_variable(char **cmd, char *param, int i)
{
	int j;

	if (ft_strstrlen(cmd) == 1)
		return (0);
	if (!ft_isalpha(param[0]) && param[0] != '_')
		return (variable_error(cmd, i));
	j = 0;
	while (param[j])
	{
		if (!ft_isalnum(param[j]) && param[j] != '_')
			return (variable_error(cmd, i));
		j++;
	}
	return (1);
}

int		check_builtins(char *line, char **cmd, t_list **env)
{
	if (!ft_strcmp(cmd[0], "echo"))
		return (my_echo(cmd, *env)); //не всегда работает корретно
	else if (!ft_strcmp(cmd[0], "cd")) //cd переменная не работает
		return (my_cd(cmd, *env));
	else if (!ft_strcmp(cmd[0], "pwd"))
		return (my_pwd());
	else if (!ft_strcmp(cmd[0], "export"))
		return (check_export(cmd, env));
	else if (!ft_strcmp(cmd[0], "unset"))
		return (check_unset(cmd, env));
	else if (!ft_strcmp(cmd[0], "env"))
		return (my_env(*env));
	else if (!ft_strcmp(cmd[0], "exit"))
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		my_exit(line, cmd, *env);
	}
	return (0);
}
