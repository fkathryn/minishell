/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:28:46 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/03 15:40:17 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s2;
	unsigned char symbol;

	s2 = (unsigned char *)s;
	symbol = (unsigned char)c;
	while (n--)
		if (*s2++ == symbol)
			return ((void *)s2 - 1);
	return (0);
}
