/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:47:12 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/05 10:38:31 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int		add_env(t_list **lst, char *name, char *value)
{
	t_env	*elem;

	if (!(elem = malloc(sizeof(t_env))))
		return (0);
	elem->name = ft_strdup(name);
	if (value)
		elem->value = ft_strdup(value);
	else
		elem->value = ft_strdup("\0");
	ft_lstadd_back(lst, ft_lstnew(elem));
	return (1);
}

int		init_env(t_list **lst, char **env)
{
	int		i;
	char	**splitted;

	i = 0;
	while (env[i])
	{
		splitted = ft_split(env[i], '=');
		if (!add_env(lst, splitted[0], splitted[1]))
			return (0);
		ft_free_strstr(splitted);
		i++;
	}
	return (1);
}
