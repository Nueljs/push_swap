/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:20:30 by macerver          #+#    #+#             */
/*   Updated: 2026/01/18 18:43:34 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		printf_putchar(char c);
int		printf_putstr(char *s);
int		printf_putnbr(int n, int fd);
int		ft_putunbr(unsigned long n, int fd);
int		ft_pvoid(void *p);
int		hex_nupper(unsigned long n);
int		hex_nlower(unsigned long n);

#endif