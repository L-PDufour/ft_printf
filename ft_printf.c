/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:40:48 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/10 20:39:28 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
// #include "utils.c"

int	ft_putnbrptr(unsigned long long int nbr, char *base)
{
	unsigned int	size;
	int				lenght;

	lenght = 0;
	size = strlen(base);
	if (size < 2)
		return (-1);
	if (nbr >= size)
		lenght = ft_putnbrptr(nbr / size, base);
	write(1, &base[nbr % size], 1);
	return (lenght + 1);
}

int	format(const char format, va_list arg)
{
	int	lenght;

	lenght = 0;
	if (format == 'c')
		lenght += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		lenght += ft_putstr(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		lenght += ft_putnbr(va_arg(arg, int));
	else if (format == 'x' || format == 'X')
		lenght += ft_puthex(va_arg(arg, int), format);
	if (format == 'p')
	{
		write(1, "0x", 2);
		lenght += 2 + ft_putnbrptr(va_arg(arg, unsigned long long),
				"0123456789abcdef");
	}
	return (lenght);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		lenght;
	int		i;

	i = 0;
	lenght = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			lenght += format(str[i + 1], arg);
			i++;
		}
		else
			lenght += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (lenght);
}
