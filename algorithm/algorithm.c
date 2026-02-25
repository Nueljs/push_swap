/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:40:44 by macerver          #+#    #+#             */
/*   Updated: 2026/02/25 05:55:26 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_target_b(t_list *node, t_list **stack)
{
	t_list	*target;
	t_list	*aux;
	t_list	*max;

	aux = (*stack);
	max = (*stack);
	target = (*stack);
	while (aux)
	{
		if ((node-> value > aux-> value) && (target-> value <= aux-> value))
		{
			target = aux;
			node-> target = target;
		}
		if (aux-> value > max-> value)
			max = aux;
		aux = aux-> next;
	}
	if (!node-> target)
		node -> target = max;
}

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	int	i;

	if (ft_lstsize((*stack_a)) > 3)
	{
		i = 2;
		while (ft_lstsize((*stack_a)) > 3 && i-- > 0)
			pb(stack_b, stack_a);
		while (ft_lstsize((*stack_a)) > 3)
		{
			calc_cost_atob(stack_a, stack_b);
			push_to_b(stack_a, stack_b);
		}
		sort_3(stack_a);
		reset_target(stack_b);
		b_to_a(stack_b, stack_a);
	}
	else if (ft_lstsize((*stack_a)) == 2)
		sort_2(stack_a);
	else
		sort_3(stack_a);
}
