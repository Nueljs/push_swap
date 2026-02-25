/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 05:23:31 by macerver          #+#    #+#             */
/*   Updated: 2026/02/25 06:15:01 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_to_a(t_list **from, t_list **to)
{
	t_list	*aux;
	t_list	*target;

	aux = (*from);
	while (aux)
	{
		target = aux-> target;
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
		aux = aux -> next;
	}
}

static void	calc_target_a(t_list *node, t_list **stack)
{
	t_list	*target;
	t_list	*aux;
	t_list	*max;

	aux = (*stack);
	max = (*stack);
	target = (*stack);
	while (aux)
	{
		if ((node-> value < aux-> value))
		{
			target = aux;
			while (aux)
			{
				if ((aux-> value < target-> value) && (aux-> value > node-> value))
					target = aux;
				aux = aux-> next;
			}
			node-> target = target;//tengo que corregir esta funcion porque me da segfault porque termino con aux en nulo y luego quiero acceder tengo que buscar otra forma
		}
		else if (aux-> value > max-> value)
			max = aux;
		node-> target = max;
		aux = aux-> next;
	}
}

void	b_to_a(t_list **from, t_list **to)
{
	t_list	*aux;

	aux = (*from);
	while (aux)
	{
		calc_target_a(aux, to);
		aux = aux-> next;
	}
	push_to_a(from, to);
}