/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:33:52 by fkathryn          #+#    #+#             */
/*   Updated: 2020/10/17 16:56:26 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*find_env(char *line, t_list *env)
{
	t_list	*tmp;
	char	*s;

	tmp = env;
	while (tmp)
	{
		if ((t_env*)tmp->content &&
			!ft_strcmp(((t_env*)tmp->content)->name, line))
		{
			if ((s = ((t_env*)tmp->content)->value))
				return (s);
			else
				return ("");
		}
		tmp = tmp->next;
	}
	return ("");
}

static	char	*ft_res_env(int i, char *buff, t_list *env)
{
	char *res;

	if (i == 0)
	{
		if (!(res = ft_strdup("$")))
			ft_error_errno_exit();
	}
	else
	{
		if (!(res = ft_strdup(find_env(buff, env))))
			ft_error_errno_exit();
	}
	return (res);
}

char			*lookup_env(char **line, t_list *env)
{
	int		i;
	char	*res;
	char	*buff;
	char	t;

	(*line)++;
	buff = (*line);
	i = 0;
	while (buff[i] && !ft_strchr(" $<>|;\'\"\\", buff[i])
			&& !ft_issymbol(buff[i]))
		i++;
	t = buff[i];
	buff[i] = 0;
	if (buff[0] == '?' || (i == 0 && t == '?'))
	{
		if (!(res = ft_itoa(g_status)))
			ft_error_errno_exit();
		*line = &buff[++i];
		return (res);
	}
	res = ft_res_env(i, buff, env);
	buff[i] = t;
	*line = &buff[i];
	return (res);
}
