/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:01:14 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/17 17:27:03 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_home(t_list *env)
{
	t_list	*tmp;
	t_env	*content;

	tmp = env;
	while (tmp)
	{
		content = (t_env*)tmp->content;
		if (content && !ft_strcmp(content->name, "HOME"))
			return (content->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	set_pwd(t_list **env)
{
	t_list	*tmp;
	t_env	*content;
	char	*path;
	t_env	*elem;

	tmp = *env;
	path = getcwd(NULL, 0);
	while (tmp)
	{
		content = (t_env*)tmp->content;
		if (content && !ft_strcmp(content->name, "PWD"))
		{
			free(content->value);
			content->value = path;
			return ;
		}
		tmp = tmp->next;
	}
	if (!(elem = malloc(sizeof(t_env))))
		return ;
	elem->name = ft_strdup("PWD");
	elem->value = path;
	ft_lstadd_back(env, ft_lstnew(elem));
	env_sort(env);
}

void	my_cd2(char **cmd, t_list **env)
{
	if (!ft_strcmp(cmd[1], "\0"))
		;
	else if (!check_dir(cmd[1]))
		return ;
	else if (chdir(cmd[1]) == 0)
		set_pwd(env);
	else
		error_from_errno(cmd[1]);
}

int		my_cd(char **cmd, t_list **env)
{
	char	*home_value;

	g_status = 0;
	if (ft_strstrlen(cmd) == 1)
	{
		if (!(home_value = find_home(*env)))
			return (error_home_not_set());
		else if (!check_dir(home_value))
			return (1);
		else if (!ft_strcmp(home_value, "\0"))
		{
			set_pwd(env);
			return (1);
		}
		else if (chdir(home_value) == 0)
			set_pwd(env);
		else
			error_from_errno(cmd[1]);
	}
	else
		my_cd2(cmd, env);
	return (1);
}
