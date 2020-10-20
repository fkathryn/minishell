/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 08:53:45 by qtamaril          #+#    #+#             */
/*   Updated: 2020/10/07 08:54:00 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *str2;

	str2 = str;
	while (*str2 != '\0')
	{
		if (*str2 >= 'A' && *str2 <= 'Z')
			*str2 += 32;
		str2++;
	}
	return (str);
}