/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:07:34 by fkathryn          #+#    #+#             */
/*   Updated: 2020/10/17 16:08:10 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*strjoin;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	strjoin = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	if (!(strjoin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * \
	sizeof(char))))
		return (NULL);
	while (s1[j])
		strjoin[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	return (strjoin);
}
