/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pvoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:52:18 by macerver          #+#    #+#             */
/*   Updated: 2026/01/18 18:43:42 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pvoid(void *p)
{
	unsigned long long	ptr;

	ptr = (unsigned long) p;
	if (!p)
		return (write(1, "(nil)", 5));
	return (printf_putstr("0x") + hex_nlower(ptr));
}
