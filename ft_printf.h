/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:43:45 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/15 13:45:32 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(const char c, int *lenght);
void	ft_putstr(const char *str, int *lenght);
void	ft_puthex(long int nb, const char format, int *lenght);
void	ft_putnbr(int nb, int *lenght);
void	ft_putnbrptr(unsigned long long int nbr, int *lenght);
void	formatter(const char format, va_list arg, int *lenght);
int		ft_printf(const char *str, ...);
void	ft_putnbru(unsigned int nb, int *lenght);

#endif
