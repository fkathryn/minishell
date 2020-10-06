/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:08:23 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/03 16:19:22 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strstrdup(char **s)
{
	int		length;
	char	**strstr;
	int		i;

	i = 0;
	length = ft_strstrlen(s);
	if (!(strstr = ft_calloc(length + 1, sizeof(char *))))
		return (NULL);
	while (i < length)
	{
		strstr[i] = ft_strdup(s[i]);
		i++;
	}
	return (strstr);
}
