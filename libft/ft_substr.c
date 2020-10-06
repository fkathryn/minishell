/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 09:19:53 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/15 15:23:51 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*substr;
	size_t		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	i = 0;
	str = (char *)s;
	if (!(substr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len-- > 0 && str[start])
		substr[i++] = str[start++];
	substr[i] = 0;
	return (substr);
}
