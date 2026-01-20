/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_nlower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:54:04 by macerver          #+#    #+#             */
/*   Updated: 2025/12/08 12:21:59 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_nlower(unsigned long n)
{
	char			c;
	char			*hex;
	static int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		hex_nlower(n / 16);
	c = hex[n % 16];
	write(1, &c, 1);
	return (++len);
}
