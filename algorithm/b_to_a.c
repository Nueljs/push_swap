/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 05:23:31 by macerver          #+#    #+#             */
/*   Updated: 2026/02/27 13:13:14 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*calc_min(t_list **stack)
{
	t_list	*min;
	t_list	*aux;

	aux = (*stack);
	min = (*stack);
	while (aux)
	{
		if (aux-> value < min-> value)
			min = aux;
		aux = aux-> next;
	}
	return (min);
}

static void	calc_target_a(t_list *node, t_list **stack)
{
	t_list	*aux;
	t_list	*target;

	aux = (*stack);
	target = (*stack);
	while (aux)
	{
		if (aux-> value > target -> value)
			target = aux;
		aux = aux-> next;
	}
	aux = (*stack);
	while (aux)
	{
		if (aux -> value > node -> value)
		{
			if (target-> value > aux-> value)
				target = aux;
		}
		aux = aux-> next;
	}
	node-> target = target;
}

void	b_to_a(t_list **from, t_list **to)
{
	t_list	*target;
	t_list	*min;

	while ((*from) != NULL)
	{
		calc_target_a((*from), to);
		min = calc_min(to);
		target = (*from)-> target;
		if (target-> value < (*from)-> value)
			target = min;
		calc_index(to);
		if (target == (*to))
			pa(to, from);
		else
		{
			while (target != (*to))
			{
				if (target -> index > ft_lstsize((*to)) / 2)
					rra(to);
				else
					ra(to);
			}
			pa(to, from);
		}
	}
}
