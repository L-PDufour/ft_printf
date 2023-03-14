/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:40:48 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/14 15:09:07 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(const char format, va_list arg)
{
	int	lenght;

	lenght = 0;
	if (format == 'c')
		lenght += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		lenght += ft_putstr(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		lenght += declenght(va_arg(arg, int));
	else if (format == 'u')
		lenght += declenght_u(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		lenght += ft_puthex(va_arg(arg, int), format);
	else if (format == 'p')
	{
		write(1, "0x", 2);
		lenght += 2 + ft_putnbrptr(va_arg(arg, unsigned long long));
	}
	else if (format == '%')
	{
		lenght = 1;
		ft_putchar('%');
	}
	else if (lenght < 0)
		return (-1);
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
	while (str[i] != '\0')
	{
		if (lenght < 0)
			return (-1);
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

