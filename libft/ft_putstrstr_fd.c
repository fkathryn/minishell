/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:06:46 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/03 18:07:03 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrstr_fd(char **splitted, int fd)
{
	int i;

	if (!splitted || fd < 0)
		return ;
	i = 0;
	while (splitted[i])
		ft_putendl_fd(splitted[i++], fd);
}
