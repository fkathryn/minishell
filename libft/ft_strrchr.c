/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:39:36 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/15 13:59:28 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			symbol;
	char			*s2;
	int				length;

	length = 0;
	symbol = (char)c;
	s2 = (char *)s;
	if (s2 != NULL)
	{
		length = ft_strlen(s2);
		while (s2[length] != symbol && length)
			length--;
	}
	if (s2[length] == symbol)
		return (&s2[length]);
	if (symbol == '\0')
		return (s2);
	return (NULL);
}
