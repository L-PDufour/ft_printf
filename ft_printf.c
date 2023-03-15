/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:40:48 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/15 13:44:15 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formatter(const char format, va_list arg, int *lenght)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int), lenght));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *), lenght));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int), lenght));
	else if (format == 'u')
		return (ft_putnbru(va_arg(arg, unsigned int), lenght));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(arg, int), format, lenght));
	else if (format == 'p')
	{
		ft_putstr("0x", lenght);
		return (ft_putnbrptr(va_arg(arg, unsigned long long), lenght));
	}
	else if (format == '%')
		return (ft_putchar('%', lenght));
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
		if (lenght == -1)
			return (-1);
		if (str[i] == '%')
		{
			formatter(str[i + 1], arg, &lenght);
			i++;
		}
		else
			ft_putchar(str[i], &lenght);
		i++;
	}
	va_end(arg);
	return (lenght);
}
