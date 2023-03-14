/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:25:28 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/14 14:47:12 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(long int nb, const char format)
{
	char			*hex;
	char			*hexm;
	int				div;
	int				len;
	unsigned int	x;

	hex = "0123456789abcdef";
	hexm = "0123456789ABCDEF";
	x = nb;
	div = 1;
	len = 0;
	while ((x / div) >= 16)
		div *= 16;
	while (div > 0)
	{
		if (format == 'x')
			ft_putchar(hex[(x / div) % 16]);
		else
			ft_putchar(hexm[(x / div) % 16]);
		div /= 16;
		len++;
	}
	return (len);
}

int	ft_putnbrptr(unsigned long long int nbr)
{
	int		lenght;
	char	*hex;

	hex = "0123456789abcdef";
	lenght = 0;
	if (nbr >= 16)
		lenght = ft_putnbrptr(nbr / 16);
	ft_putchar(hex[nbr % 16]);
	return (lenght + 1);
}
