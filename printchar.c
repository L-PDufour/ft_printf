/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:21:09 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/15 13:52:09 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, int *lenght)
{
	if (*lenght == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*lenght = -1;
	else if (*lenght >= 0)
		*lenght += 1;
}

void	ft_putstr(const char *str, int *lenght)
{
	if (*lenght == -1)
		return ;
	if (!str)
	{
		ft_putstr("(null)", lenght);
		return ;
	}
	while (*str != '\0')
	{
		ft_putchar(*str, lenght);
		str++;
	}
}
