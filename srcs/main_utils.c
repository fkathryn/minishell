/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 10:44:46 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/06 16:30:19 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_prompt(void)
{
	char	*path;

	ft_putstr_fd(GREEN, STDOUT_FILENO);
	ft_putstr_fd("minishell:~", STDOUT_FILENO);
	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putstr_fd(DEFAULT, STDOUT_FILENO);
	free(path);
}

int		is_separator(char c)
{
	if (c == ' ' || c == '<' || c == '>' || c == '|' || c == ';' || c == '\'' \
	|| c == '\"')
		return (1);
	return (0);
}

void	ft_print_env(char *s)
{
	if (s[0] == '/')
	{
		ft_putstr_fd(SHELL, STDERR_FILENO);
		ft_putstr_fd(s, STDERR_FILENO);
		ft_putendl_fd(IS_A_DIR, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd(SHELL, STDERR_FILENO);
		ft_putstr_fd(s, STDERR_FILENO);
		ft_putendl_fd(CMD_NOT_FOUND, STDERR_FILENO);
	}
}

void		replase_env(char **cmd, t_list **env)
{
	t_list	*tmp;
	int		i;
	char	*s;
	int		len;

	tmp = (*env);
	i = 0;
	while(cmd[i])
	{
		if (cmd[i][0] != '$')
			i++;
		else
		{
			if ((s = find_env(&cmd[i][1], env)))
			{
				len = ft_strlen(s);
				cmd[i] = ft_realloc(cmd[i], len);
				free(cmd[i]); 
				cmd[i] = s;
			}
			i++;
		}
	}
}

char 	*find_env(char *line, t_list **env)
{
	t_list	*tmp;
	char	*s;

	tmp = (*env);
	while (tmp)
	{
		if ((t_env*)tmp->content && !ft_strcmp(((t_env*)tmp->content)->name, line))
			return ((s = ((t_env*)tmp->content)->value));
		tmp = tmp->next;
	}
	return (NULL);
}
