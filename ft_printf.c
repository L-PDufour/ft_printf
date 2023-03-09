/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:40:48 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/09 14:56:44 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar(char c, int *lenght)
{
	write(1, &c, 1);
	(*lenght)++;
}

static void	ft_putstr(char *s, int *lenght)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		(*lenght)++;
		i++;
	}
}

static int	declenght(int n)
{
	int	len;
	int	x;

	len = 0;
	if (n <= 0)
		len++;
	x = n;
	while (x != 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

char	*decitoa(int n)
{
	char		*str;
	int			len;
	long int	b;

	b = n;
	len = declenght(b);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (b == 0)
		*str = '0';
	if (b < 0)
	{
		b *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	while (b != 0)
	{
		str[--len] = (b % 10) + 48;
		b /= 10;
	}
	return (str);
}

static int	hexlenght(long int n)
{
	long int	len;
	long int	x;

	len = 0;
	if (n <= 0)
		len++;
	x = n;
	while (x != 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}

static char	*hexitoa(long int n, int a)
{
	char		*str;
	int			len;
	long int	b;
	long int	digit;

	b = n;
	len = hexlenght(b);
	str = (char *)calloc((sizeof(char)), (hexlenght(b)) + 1);
	if (!str)
		return (NULL);
	if (b == 0)
		*str = '0';
	if (b < 0)
	{
		b *= -1;
		str[0] = '-';
	}
	while (b != 0)
	{
		digit = b % 16;
		if (digit > 10)
			str[--len] = a + digit - 10;
		else
			str[--len] = digit + '0';
		b /= 16;
	}
	return (str);
}

static void format(char *str, int i, va_list arg, int lenght)
{
	
		if (str[i] == 'c')
			ft_putchar(va_arg(arg, int), &lenght);
		if (str[i] == 's')
		ft_putstr(va_arg(arg, char *), &lenght);
		if (str[i] == 'd' || str[i] == 'i')
		ft_putstr(decitoa(va_arg(arg, int)), &lenght);
		else if (str[i] == 'u')
		ft_putstr(decitoa(va_arg(arg, unsigned int)), &lenght);
		else if (str[i] == 'x')
		ft_putstr(hexitoa(va_arg(arg, int), 97), &lenght);
		else if (str[i] == 'X')
		ft_putstr(hexitoa(va_arg(arg, int), 65), &lenght);
		if (str[&i] == 'p')
		ft_putstr(itoa(va_arg(arg, int), 16, 97), &lenght);

	}

int	ft_printf(char *str, ...)
{
	va_list	arg;
	int		i;
	int		lenght;
	lenght = 0;
	i = 0;
	va_start(arg, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format(str, i, arg, lenght);
		}
		else 
			ft_putchar(str[i], &lenght);
		i++;
	}
	va_end(arg);
	return (lenght);
}
