/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:57:02 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/03 13:37:16 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *dest2;
	unsigned char *src2;
	unsigned char symbol;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	symbol = (unsigned char)c;
	while (n--)
	{
		*dest2 = *src2;
		if (*dest2 == symbol)
			return ((void *)dest2 + 1);
		dest2++;
		src2++;
	}
	return (0);
}
