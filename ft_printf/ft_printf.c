/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:47:16 by macerver          #+#    #+#             */
/*   Updated: 2026/01/18 18:35:24 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_type(char c, va_list args)
{
	if (c == 'c')
		return (printf_putchar(va_arg(args, int)));
	else if (c == 's')
		return (printf_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_pvoid(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (printf_putnbr(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (hex_nlower(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (hex_nupper(va_arg(args, unsigned int)));
	else if (c == '%')
		return (printf_putchar('%'));
	return (printf_putchar('%') + printf_putchar(c));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
			{
				va_end(args);
				return (-1);
			}
			i++;
			len += find_type(str[i], args);
		}
		else
			len += printf_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
