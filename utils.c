/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:21:09 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/10 20:24:56 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	  {
    write (1,"(null)", 6);
    return (6);
    }	
  i = 0;

  while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	declenght(int n)
{
	long int	len;
	long int	x;

	len = 0;
	if (n <= 0)
		len++;
	x = n;
	while (!(x == 0))
	{
		x /= 10;
		len++;
	}
	return (len);
}

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

int	ft_putnbr(int nb)
{
	int	x;

	x = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return (declenght(x));
}

int	ft_putnbru(unsigned int nb)
{
	int	x;

	x = nb;
	//if (nb < 0)
	//{
	//	ft_putchar('-');
	//	nb *= -1;
	//}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return (declenght(x));
}
