/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:42:27 by fkathryn          #+#    #+#             */
/*   Updated: 2020/10/18 19:03:16 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	ft_str_utils(char *str_var, char **line,
								char **temp, int *index)
{
	if (str_var)
	{
		(*index) += ft_strlen(str_var);
		if (!((*temp) = ft_strjoin_gnl((*temp), str_var)))
			ft_error_errno_exit();
		free(str_var);
	}
	else
	{
		(*temp) = ft_str_realloc((*temp), 1);
		(*temp)[(*index)++] = **line;
		(*line)++;
	}
}

char			*get_str_double_quotes(char **line, t_list *env)
{
	char	*temp;
	int		index;
	char	*str_var;

	index = 0;
	temp = NULL;
	(*line)++;
	while (**line && **line != '\"')
	{
		g_flag = 1;
		str_var = NULL;
		if (**line == '\\' && (*(*line + 1) == '$' || \
		*(*line + 1) == '\\' || *(*line + 1) == '\"'))
			(*line)++;
		if (**line == '$')
			str_var = lookup_env(line, env);
		ft_str_utils(str_var, line, &temp, &index);
	}
	if (**line == '\"')
		(*line)++;
	if (!g_flag)
		temp = ft_strdup("");
	return (temp);
}

char			*get_str_single_quotes(char **line)
{
	char	*temp;
	int		index;

	index = 0;
	temp = NULL;
	(*line)++;
	while (**line && **line != '\'')
	{
		g_flag = 1;
		temp = ft_str_realloc(temp, 1);
		temp[index++] = **line;
		(*line)++;
	}
	if (**line == '\'')
		(*line)++;
	if (!g_flag)
		temp = ft_strdup("");
	return (temp);
}

char			*get_str_regular(char **line, t_list *env)
{
	char	*temp;
	int		index;
	char	*str_var;

	index = 0;
	temp = NULL;
	g_flag = 1;
	while (**line && !ft_strchr(" \t<>|;\'\"", **line))
	{
		str_var = NULL;
		if (**line == '\\')
			(*line)++;
		else if (**line == '$')
		{
			g_flag = 1;
			str_var = lookup_env(line, env);
		}
		ft_str_utils(str_var, line, &temp, &index);
	}
	return (temp);
}

char			*parse_argument(char **line, t_list *env)
{
	char	*temp;
	char	*res;

	res = NULL;
	g_flag = 0;
	while (**line && !ft_strchr("|><;", **line))
	{
		temp = NULL;
		if (ft_isspace(**line))
			break ;
		if (**line == '\"')
			temp = get_str_double_quotes(line, env);
		else if (**line == '\'')
			temp = get_str_single_quotes(line);
		else
			temp = get_str_regular(line, env);
		if (temp && !(res = ft_strjoin_gnl(res, temp)))
			ft_error_errno_exit();
		if (temp)
			free(temp);
	}
	return (res);
}
