/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:14:51 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/04 15:29:33 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		length;
	char	*str;

	length = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	ft_strlcpy(str, s, length + 1);
	return (str);
}
