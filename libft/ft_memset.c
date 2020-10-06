/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 09:12:01 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/03 09:41:43 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *s2;
	unsigned char symbol;

	s2 = (unsigned char *)s;
	symbol = (unsigned char)c;
	while (n--)
		*s2++ = symbol;
	return (s);
}
