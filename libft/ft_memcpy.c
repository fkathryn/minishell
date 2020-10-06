/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 10:59:26 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/14 09:32:29 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	if (!n || (!dest && !src))
		return (dest);
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (n--)
		*dest2++ = *src2++;
	return (dest);
}
