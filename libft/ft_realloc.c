/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:04:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/03 17:13:24 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(char *src, int size)
{
	char	*temp;

	temp = src;
	if (src != NULL)
	{
		size += ft_strlen(src);
		src = (char*)ft_calloc(1, (size_t)size + 1);
		ft_strcpy(src, temp);
		free(temp);
	}
	else
		src = (char*)ft_calloc(1, (size_t)size + 1);
	return (src);
}
