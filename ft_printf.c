/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:40:48 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/08 19:58:53 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

static int	ft_lenght(long int n, int base)
{
	int			len;
	long int	x;

	len = 0;
	if (n <= 0)
		len++;
	x = n;
	while (x != 0)
	{
		x /= base;
		len++;
	}
	return (len);
}

static char	*itoa(long int n, int base, int a)
{
	char		*str;
	int			len;
	long int	b;
	long int	digit;

	b = n;
	len = ft_lenght(b, base);
	str = (char *)malloc(sizeof(char) * ft_lenght(b, base) + 1);
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
		digit = b % base;
		if (digit > 10)
			str[--len] = a + digit - 10;
		else
			str[--len] = digit + '0';
		b /= base;
	}
	return (str);
}

int	ft_printf(char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(arg, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(arg, int));
			if (str[i] == 's')
				ft_putstr(va_arg(arg, char *));
				// j = j + ft_strlen((va_arg(arg, char *)));
			if (str[i] == 'd' || str[i] == 'i')
				ft_putstr(itoa(va_arg(arg, int), 10, 97));
			if (str[i] == 'u')
				ft_putstr(itoa(va_arg(arg, unsigned int), 10, 97));
			if (str[i] == 'x')
				ft_putstr(itoa(va_arg(arg, int), 16, 97));
			if (str[i] == 'X')
				ft_putstr(itoa(va_arg(arg, int), 16, 65));
			if (str[i] == 'p')
				ft_putstr(itoa(va_arg(arg, int), 16, 97));			
		}
		else
			ft_putchar(str[i]);
		i++;
	}	
	va_end(arg);
	return (j);
}
