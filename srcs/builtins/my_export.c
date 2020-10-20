/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:10:07 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/17 17:26:35 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_list *env)
{
	t_env	*content;

	if (!env)
		return ;
	while (env)
	{
		content = (t_env*)env->content;
		if (content)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(content->name, STDOUT_FILENO);
			if (content->value)
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(content->value, STDOUT_FILENO);
				ft_putendl_fd("\"", STDOUT_FILENO);
			}
			else
				ft_putendl_fd("", STDOUT_FILENO);
		}
		env = env->next;
	}
}

void	export2(t_list **env, char **vars, char **splitted, int i)
{
	t_env	*elem;
	char	*p_value;

	p_value = ft_strchr(vars[i], '=');
	if (p_value)
		add_env(env, splitted[0], p_value + 1);
	else
	{
		if (!(elem = malloc(sizeof(t_env))))
			ft_error_errno_exit();
		if (!(elem->name = ft_strdup(splitted[0])))
			ft_error_errno_exit();
		elem->value = NULL;
		ft_lstadd_back(env, ft_lstnew(elem));
		env_sort(env);
	}
}

void	export(t_list **env, char **vars, char **splitted, int i)
{
	t_list	*tmp;
	t_env	*curr_env;
	char	*p_value;

	tmp = *env;
	while (tmp)
	{
		curr_env = (t_env*)tmp->content;
		if (curr_env && !ft_strcmp(curr_env->name, splitted[0]))
		{
			p_value = ft_strchr(vars[i], '=');
			if (p_value)
			{
				free(curr_env->value);
				if (!(curr_env->value = ft_strdup(p_value + 1)))
					ft_error_errno_exit();
			}
			return ;
		}
		tmp = tmp->next;
	}
	export2(env, vars, splitted, i);
}

int		check_export(char **cmd, t_list **env)
{
	char	**splitted;
	int		i;

	i = 1;
	g_status = 0;
	if (ft_strstrlen(cmd) > 1)
	{
		while (cmd[i])
		{
			splitted = ft_split(cmd[i++], '=');
			if (check_variable(cmd, splitted[0], i - 1))
				export(env, cmd, splitted, i - 1);
			ft_free_strstr(splitted);
		}
	}
	else if (ft_strstrlen(cmd) == 1)
		print_export(*env);
	return (1);
}
