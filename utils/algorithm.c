/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:40:44 by macerver          #+#    #+#             */
/*   Updated: 2026/02/22 06:33:05 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_index(t_list **stack)
{
	t_list	*aux;
	int		i;

	i = 1;
	aux = (*stack);
	while (aux)
	{
		aux -> index = i;
		ft_printf("%d\n", aux -> index);
		i++;
		aux = aux -> next;
	}
}

static void	cost(t_list *node, t_list **stack, t_list **target_stack)
{
	int		cost;
	t_list	*target;

	cost = 1;
	target = node -> target;
	if (node -> index > ft_lstsize(stack) / 2)
	{
		if (target -> index > ft_lstsize(target_stack) / 2)
			cost += rr_cost(node -> index, ft_lstsize(stack),
				target -> index, ft_lstsize(target_stack));
		else if (target -> index <= ft_lstsize(target_stack) / 2)
			cost += (ft_lstsize(stack) - node  -> index) + target -> index;
	}
	else if (node  -> index <= ft_lstsize(target_stack) / 2)
	{
		if (target -> index <= ft_lstsize(target_stack) / 2)
			cost += r_cost(node -> index, target -> index);
		cost += node -> index - 1;
	}
}

static void	calc_target(t_list *node, t_list **stack)
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
	t_list	*aux;

	aux = (*stack_a);
	while (aux)
	{
		calc_target(*stack_a, stack_b);
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
