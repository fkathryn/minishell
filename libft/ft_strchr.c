/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:09:34 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/04 11:39:17 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*s2;
	char	symbol;

	s2 = (char *)s;
	symbol = (char)c;
	while (*s2 != symbol)
	{
		if (*s2 == '\0')
			return (0);
		s2++;
	}
	return (s2);
}
