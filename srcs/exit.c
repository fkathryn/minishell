/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:38:31 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/05 10:41:28 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_exit(char *line, char **cmd, t_list *env)
{
	// free(line);
	(void)line;
	(void)cmd;
	(void)env;
	ft_free_strstr(cmd);
	// free_env(env);
	exit(0);
}
