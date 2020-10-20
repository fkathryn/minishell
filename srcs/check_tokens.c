/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:50:01 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/18 19:06:04 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_back_redirs(char **line)
{
	int		count;

	count = 1;
	while (**line && **line == '<')
	{
		count++;
		(*line)++;
	}
	if (count >= 4)
	{
		if (count == 4)
			ft_putendl_fd("minishell: syntax error near unexpected token `<\'", \
			STDERR_FILENO);
		else if (count == 5)
			ft_putendl_fd("minishell: syntax error near unexpected token `<<\'", \
			STDERR_FILENO);
		else if (count > 5)
			ft_putendl_fd("minishell: syntax error near unexpected token `<<<\'", \
			STDERR_FILENO);
		g_redir_error = 1;
		g_status = 258;
		return (0);
	}
	return (1);
}

int		check_redirs(char **line)
{
	int		count;

	count = 0;
	while (**line && **line == '>')
	{
		count++;
		(*line)++;
	}
	if (count == 1)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>\'", \
		STDERR_FILENO);
		g_redir_error = 1;
		g_status = 258;
		return (0);
	}
	else if (count > 1)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>>\'", \
		STDERR_FILENO);
		g_status = 258;
		g_redir_error = 1;
		return (0);
	}
	return (1);
}

int		check_dir_in_begin2(char **line)
{
	if (**line == ';' && (*(*line + 1) == ';'))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;;\'", \
		STDERR_FILENO);
		g_status = 258;
		return (0);
	}
	else if (**line == ';')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `;\'", \
		STDERR_FILENO);
		g_status = 258;
		return (0);
	}
	return (1);
}

int		check_dir_in_begin(char **line)
{
	while (ft_isspace(**line))
		(*line)++;
	if (**line == '|' && (*(*line + 1) == '|'))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `||\'", \
		STDERR_FILENO);
		g_status = 258;
		return (0);
	}
	else if (**line == '|')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|\'", \
		STDERR_FILENO);
		g_status = 258;
		return (0);
	}
	else if (**line == ';')
		return (check_dir_in_begin2(line));
	return (1);
}
