/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:55:42 by macerver          #+#    #+#             */
/*   Updated: 2026/01/20 18:54:57 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#  define PUSH SWAP_H

#include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

int	ft_printf(const char *str, ...);
int	ft_atoi(const char *nptr);

#endif