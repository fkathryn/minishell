/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:08:24 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/17 17:25:10 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_pwd(char *strlowcase)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putendl_fd(path, 1);
	free(path);
	free(strlowcase);
	return (1);
}
