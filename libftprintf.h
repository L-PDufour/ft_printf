/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:43:45 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/10 20:39:51 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	declenght(int n);
int	ft_puthex(long int nb, const char format);
int	ft_putnbr(int nb);
int	ft_putnbrptr(unsigned long long int nbr, char *base);
int	format(const char format, va_list arg);
int	ft_printf(const char *str, ...);

#endif
