/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:42:58 by macerver          #+#    #+#             */
/*   Updated: 2026/01/18 18:36:28 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putunbr(unsigned long n, int fd)
{
	char	c;
	int		len;

	len = count_digits(n);
	if (n >= 10)
		ft_putunbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
	return (len);
}
