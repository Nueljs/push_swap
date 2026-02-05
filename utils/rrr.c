/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:57:30 by macerver          #+#    #+#             */
/*   Updated: 2026/02/05 12:07:02 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}
