/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:31:40 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/12 09:48:22 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long int n)
{
	long int i;

	i = 0;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (++i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	size_t			i;
	long int		n2;
	char			*str;

	n2 = (long int)n;
	i = 0;
	if (n2 < 0)
	{
		i = 1;
		n2 *= -1;
	}
	len = ft_intlen(n2) + i;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	str[len] = 0;
	while (len-- > i)
	{
		str[len] = n2 % 10 + '0';
		n2 /= 10;
	}
	if (i)
		str[0] = '-';
	return (str);
}
