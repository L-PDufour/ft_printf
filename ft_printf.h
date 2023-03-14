/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:43:45 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/14 15:07:17 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		declenght(int n);
int		declenght_u(unsigned int n);
int		ft_puthex(long int nb, const char format);
void	ft_putnbr(int nb);
int		ft_putnbrptr(unsigned long long int nbr);
int		format(const char format, va_list arg);
int		ft_printf(const char *str, ...);
void	ft_putnbru(unsigned int nb);

#endif
