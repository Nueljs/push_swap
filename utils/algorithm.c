/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:40:44 by macerver          #+#    #+#             */
/*   Updated: 2026/02/18 19:22:26 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_target(t_list *node, t_list **stack)
{
	int	max;
	int	min;

	max = node -> value;
	min = node -> value;
	while (stack)
	{
		if((*stack) -> value > node -> value && (*stack) -> value > max)
			max = (*stack) -> value;
		if((*stack) -> value < node -> value && (*stack) -> value < min)
			min = (*stack) -> value;
	}
	
}

static void	calculate_cost(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a))
	{
		calc_target(*stack_a, stack_b);
	}
}

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	int	i;

	if (ft_lstsize((*stack_a)) > 3)
	{
		i = 2;
		while (ft_lstsize((*stack_a)) > 3 && i-- > 0)
			pb(stack_b, stack_a);
		calculate_cost(stack_a, stack_b);
	}
	else if (ft_lstsize((*stack_a)) == 2)
		sort_2(stack_a);
	else
		sort_3(stack_a);
}
