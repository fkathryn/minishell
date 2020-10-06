/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 08:33:28 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/15 12:29:07 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_findchar(char symbol, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == symbol)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	z;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_findchar(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && s1[j - 1] && ft_findchar(s1[j - 1], set))
		j--;
	if (!(result = malloc((j - i + 1) * sizeof(char))))
		return (NULL);
	z = 0;
	while (i < j)
		result[z++] = s1[i++];
	result[z] = 0;
	return (result);
}
