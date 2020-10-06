/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 09:54:56 by qtamaril          #+#    #+#             */
/*   Updated: 2020/06/09 10:15:35 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		number;
	int		negative;

	number = 0;
	negative = 1;
	while (*str == ' ' || *str == '\n'
	|| *str == '\f' || *str == '\v'
	|| *str == '\r' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	if (!((*str >= '0') && (*str <= '9')))
		return (0);
	while ((*str >= '0') && (*str <= '9'))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * negative);
}
