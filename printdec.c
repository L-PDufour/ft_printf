/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:23:48 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/15 13:44:31 by ldufour          ###   ########.fr       */
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
