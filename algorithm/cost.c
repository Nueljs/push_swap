/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 04:49:09 by macerver          #+#    #+#             */
/*   Updated: 2026/02/24 04:52:06 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rr_cost(int index_stack, int size_stack, int index_t, int size_t)
{
	int	cost_a;
	int	cost_b;

	cost_a = size_stack - index_stack;
	cost_b = size_t - index_t;
	if (cost_a > cost_b)
		return (cost_b + (cost_a - cost_b) + 1);
	return (cost_a + (cost_b - cost_a) + 1);
}

static int	r_cost(int i_node, int i_target)
{
	if (i_node > i_target)
		return (i_node - 1);
	return (i_target - 1);
}

static void	cost(t_list *node, t_list **stack, t_list **target_stack)
{
	int		cost;
	t_list	*target;

	cost = 1;
	target = node -> target;
	if (node -> index > ft_lstsize((*stack)) / 2)
	{
		if (target -> index > ft_lstsize((*target_stack)) / 2)
			cost += rr_cost(node -> index, ft_lstsize((*stack)),
					target -> index, ft_lstsize((*target_stack)));
		else if (target -> index <= ft_lstsize((*target_stack)) / 2)
			cost += (ft_lstsize((*stack)) - node -> index) + target -> index;
	}
	else if (node -> index <= ft_lstsize((*stack)) / 2)
	{
		if (target -> index <= ft_lstsize((*target_stack)) / 2)
			cost += r_cost(node -> index, target -> index);
		else
			cost += node -> index
				+ (ft_lstsize((*target_stack)) - target -> index);
	}
	node -> cost = cost;
}

void	calc_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	aux = (*stack_a);
	while (aux)
	{
		calc_target(aux, stack_b);
		aux = aux -> next;
	}
	aux = (*stack_a);
	calc_index(stack_a);
	calc_index(stack_b);
	while (aux)
	{
		cost(aux, stack_a, stack_b);
		aux = aux -> next;
	}
}