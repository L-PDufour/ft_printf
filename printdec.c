/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:23:48 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/14 15:36:56 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	declenght(int n)
{
	long int	len;
	long int	x;

	len = 0;
	x = n;
	if (x <= 0)
	{
		len++;
		x *= -1;
	}
	while (x > 0)
	{
		len++;
		x /= 10;
	}
	if (&ft_putnbr(n) == 0)
		return ;
	return (len);
}

void	ft_putnbr(int nb)
{
	long int	x;

	x = nb;
	if (x < 0)
	{
		if (ft_putchar('-') == -1)
			return ;
		x *= -1;
	}
	if (x >= 10)
	{
		ft_putnbr(x / 10);
		x = x % 10;
	}
	if (x <= 10)
		if (ft_putchar(x + 48) == -1)
			return ;
}

void	ft_putnbru(unsigned int nb)
{
	long int	x;

	x = nb;
	if (x >= 10)
	{
		ft_putnbr(x / 10);
		x = x % 10;
	}
	if (x < 10)
		ft_putchar(x + 48);
}

int	declenght_u(unsigned int n)
{
	long int	len;
	long int	x;

	len = 0;
	x = n;
	if (x < 0)
	{
		x *= -1;
		x = 4294767296 - x;
	}
	if (x == 0)
		return (declenght(0));
	while (x > 0)
	{
		len++;
		x /= 10;
	}
	ft_putnbru(n);
	return (len);
}
