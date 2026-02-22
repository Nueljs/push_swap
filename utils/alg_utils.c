/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 05:22:20 by macerver          #+#    #+#             */
/*   Updated: 2026/02/22 17:07:02 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr_cost(int index_stack, int size_stack, int index_t, int size_t)
{
	int	cost_a;
	int	cost_b;
	
	cost_a = size_stack - index_stack;
	cost_b = size_t - index_t;
	if (cost_a > cost_b)
		return (cost_b + (cost_a - cost_b) + 1);
	return (cost_a + (cost_b - cost_a) + 1);
}

int	r_cost(int i_node, int i_target)
{
	if(i_node > i_target)
		return (i_node - 1);
	return (i_target - 1);
}