/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:30:49 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/03 17:32:52 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strstr_realloc(char **src, int size)
{
	char	**temp;
	int		i;

	temp = src;
	i = 0;
	if (src)
	{
		size += ft_strstrlen(src);
		src = (char**)malloc(sizeof(char*) * (size + 1));
		while (i < size)
		{
			src[i] = temp[i];
			i++;
		}
		src[i] = NULL;
		free(temp);
	}
	else
	{
		src = (char**)malloc(sizeof(char*) * (size + 1));
		src[size] = NULL;
	}
	return (src);
}
