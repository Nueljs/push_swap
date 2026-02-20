/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:40:44 by macerver          #+#    #+#             */
/*   Updated: 2026/02/20 06:08:13 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_target(t_list *node, t_list **stack)
{
	int		target;
	t_list	*aux;
	t_list	*max;

	max = (*stack);
	target = (*stack) -> value;
	aux = (*stack) -> next;
	while (aux)
	{
		if ((aux -> value > node -> value) && (aux -> value > max -> value))
			max = aux;
		if ((node -> value > aux -> value) && (aux -> value > target))
			node -> target = aux;
		aux = aux -> next;
	}
	if (node -> target == NULL)
		node -> target = max;
}

static void	calc_cost(t_list **stack_a, t_list **stack_b)
{
	// while ((*stack_a))
	// {
	// }
	calc_target(*stack_a, stack_b);
}

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	int	i;

	if (ft_lstsize((*stack_a)) > 3)
	{
		i = 2;
		while (ft_lstsize((*stack_a)) > 3 && i-- > 0)
			pb(stack_b, stack_a);
		calc_cost(stack_a, stack_b);
	}
	else if (ft_lstsize((*stack_a)) == 2)
		sort_2(stack_a);
	else
		sort_3(stack_a);
}
