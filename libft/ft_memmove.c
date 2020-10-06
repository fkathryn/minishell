/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:37:52 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/14 09:33:59 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dest2;
	unsigned char *src2;

	if (!n || (!dest && !src))
		return (dest);
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest2 < src2)
		while (n--)
			*dest2++ = *src2++;
	else
	{
		dest2 += n;
		src2 += n;
		while (n--)
			*--dest2 = *--src2;
	}
	return (dest);
}
