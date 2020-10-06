/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:02:25 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/12 08:53:42 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	dest_len;

	i = 0;
	len = 0;
	dest_len = ft_strlen(dst);
	while (dst[len] && len < size)
		len++;
	if (len >= size)
		return (size + ft_strlen(src));
	while (src[i] && i < (size - dest_len - 1))
	{
		dst[len + i] = ((char *)src)[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
