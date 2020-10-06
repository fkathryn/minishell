/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:17 by qtamaril          #+#    #+#             */
/*   Updated: 2020/05/12 09:15:11 by qtamaril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_recursion(long int nb, int fd)
{
	if (nb > 9)
		ft_putnbr_recursion(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = (long int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	ft_putnbr_recursion(nb, fd);
}
