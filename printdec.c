/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:23:48 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/15 13:48:43 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *lenght)
{
	long int	x;

	x = nb;
	if (x < 0)
	{
		ft_putchar(('-'), lenght);
		x *= -1;
	}
	if (x >= 10)
	{
		ft_putnbr((x / 10), lenght);
		x = x % 10;
	}
	if (x <= 10)
		ft_putchar((x + 48), lenght);
}

void	ft_putnbru(unsigned int nb, int *lenght)
{
	long int	x;

	x = nb;
	if (x >= 10)
	{
		ft_putnbr((x / 10), lenght);
		x = x % 10;
	}
	if (x < 10)
		ft_putchar((x + 48), lenght);
}

void	ft_puthex(long int nb, const char format, int *lenght)
{
	char			*hex;
	char			*hexm;
	int				div;
	unsigned int	x;

	hex = "0123456789abcdef";
	hexm = "0123456789ABCDEF";
	x = nb;
	div = 1;
	while ((x / div) >= 16)
		div *= 16;
	while (div > 0)
	{
		if (format == 'x' )
			ft_putchar((hex[(x / div) % 16]), lenght);
		if (format == 'X')
			ft_putchar((hexm[(x / div) % 16]), lenght);
		div /= 16;
	}
}

void	ft_putnbrptr(unsigned long long int nbr, int *lenght)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbrptr((nbr / 16), lenght);
	ft_putchar((hex[nbr % 16]), lenght);
}
