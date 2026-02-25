/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 05:22:20 by macerver          #+#    #+#             */
/*   Updated: 2026/02/25 05:21:37 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_target(t_list **stack)
{
	t_list	*aux;

	aux = (*stack);
	while (aux)
	{
		aux-> target = NULL;
		aux = aux-> next;
	}
}

void	calc_index(t_list **stack)
{
	t_list	*aux;
	int		i;

	i = 1;
	aux = (*stack);
	while (aux)
	{
		aux -> index = i;
		i++;
		aux = aux -> next;
	}
}

void	push_to_b(t_list **from, t_list **to)
{
	t_list	*min_cost;
	t_list	*aux;

	aux = (*from);
	min_cost = (*from);
	while (aux)
	{
		if (aux -> cost < min_cost -> cost)
			min_cost = aux;
		aux = aux -> next;
	}
	if (min_cost -> index > ft_lstsize(*from) / 2)
		ejecute_rra(min_cost, from, to);
	else
		ejecute_ra(min_cost, from, to);
	pb(to, from);
}

