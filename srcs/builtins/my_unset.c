/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:35:02 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/17 17:24:30 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_list_elem2(t_list **env)
{
	free(*env);
	*env = NULL;
}

void	remove_list_elem(t_list **env, t_list *list_prev)
{
	t_list	*temp_element;

	free(((t_env*)(*env)->content)->name);
	((t_env*)(*env)->content)->name = NULL;
	free(((t_env*)(*env)->content)->value);
	((t_env*)(*env)->content)->value = NULL;
	free((t_env*)(*env)->content);
	if (list_prev)
	{
		list_prev->next = (*env)->next;
		free(*env);
		*env = NULL;
	}
	else if ((*env)->next)
	{
		temp_element = (*env)->next;
		(*env)->content = (*env)->next->content;
		(*env)->next = (*env)->next->next;
		free(temp_element);
		temp_element = NULL;
	}
	else if (ft_lstsize(*env) == 1)
		remove_list_elem2(env);
}

void	my_unset(t_list **env, char **vars, int i)
{
	t_env	*curr_env;
	t_list	*list_prev;
	t_list	*temp;

	list_prev = NULL;
	temp = *env;
	g_status = 0;
	while (temp)
	{
		curr_env = (t_env*)(temp)->content;
		if (curr_env && !ft_strcmp(curr_env->name, vars[i]))
		{
			remove_list_elem(&temp, list_prev);
			break ;
		}
		list_prev = temp;
		(temp) = (temp)->next;
	}
}

int		check_unset(char **cmd, t_list **env)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		if (check_variable(cmd, cmd[i], i))
			my_unset(env, cmd, i);
		i++;
	}
	return (1);
}
