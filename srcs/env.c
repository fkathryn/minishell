/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:47:12 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/17 17:55:57 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_strstr(t_list *env)
{
	char	**strstr;
	int		lstsize;
	int		y;
	t_env	*content;

	lstsize = ft_lstsize(env);
	if (!(strstr = ft_calloc(lstsize + 1, sizeof(char *))))
		ft_error_errno_exit();
	y = 0;
	while (env)
	{
		content = (t_env*)env->content;
		if (content && content->value)
		{
			if (!(strstr[y] = ft_strjoin_gnl(strstr[y], content->name)))
				ft_error_errno_exit();
			if (!(strstr[y] = ft_strjoin_gnl(strstr[y], "=")))
				ft_error_errno_exit();
			if (!(strstr[y] = ft_strjoin_gnl(strstr[y], content->value)))
				ft_error_errno_exit();
			y++;
		}
		env = env->next;
	}
	return (strstr);
}

void	free_env(t_list *lst)
{
	t_list	*tmp;

	while (lst && (t_env*)lst->content)
	{
		free(((t_env*)lst->content)->name);
		free(((t_env*)lst->content)->value);
		free((t_env*)lst->content);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	env_sort(t_list **begin_list)
{
	t_list	*element;
	t_list	*element2;
	t_list	*temp;

	element = *begin_list;
	while (element)
	{
		element2 = *begin_list;
		while (element2->next)
		{
			if ((t_env*)element2->content && (t_env*)element2->next->content \
			&& ft_strcmp(((t_env*)element2->content)->name, \
			((t_env*)element2->next->content)->name) > 0)
			{
				temp = element2->content;
				element2->content = element2->next->content;
				element2->next->content = temp;
			}
			element2 = element2->next;
		}
		element = element->next;
	}
}

int		add_env(t_list **lst, char *name, char *value)
{
	t_env	*elem;

	if (!(elem = malloc(sizeof(t_env))))
		ft_error_errno_exit();
	if (!(elem->name = ft_strdup(name)))
		ft_error_errno_exit();
	if (value)
	{
		if (!(elem->value = ft_strdup(value)))
			ft_error_errno_exit();
	}
	else
	{
		if (!(elem->value = ft_strdup("\0")))
			ft_error_errno_exit();
	}
	ft_lstadd_back(lst, ft_lstnew(elem));
	env_sort(lst);
	return (1);
}

void	init_env(t_list **lst, char **env)
{
	int		i;
	char	**splitted;

	i = 0;
	while (env[i])
	{
		splitted = ft_split(env[i], '=');
		add_env(lst, splitted[0], splitted[1]);
		ft_free_strstr(splitted);
		i++;
	}
}
