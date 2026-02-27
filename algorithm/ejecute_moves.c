/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejecute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 04:43:44 by macerver          #+#    #+#             */
/*   Updated: 2026/02/27 13:12:08 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ejecute_rrr(t_list *node, t_list *target, t_list **from, t_list **to)
{
	while (node != (*from) && target != (*to))
		rrr(from, to);
	if (node != (*from))
	{
		while (node != (*from))
			rra(from);
	}
	else if (target != (*to))
		while (target != (*to))
			rrb(to);
}
static void	ejecute_rr(t_list *node, t_list *target, t_list **from, t_list **to)
{
	while (node != (*from) && target != (*to))
		rr(from, to);
	if (node != (*from))
	{
		while (node != (*from))
			ra(from);
	}
	else if (target != (*to))
		while (target != (*to))
			rb(to);
}

void	ejecute_rra(t_list *node, t_list **from, t_list **to)
{
	t_list	*target;

	target = node -> target;
	if (target -> index > ft_lstsize((*to)) / 2)
		ejecute_rrr(node, target, from, to);
	else
	{
		while (node != (*from))
			rra(from);
		while (target != (*to))
			rb(to);
	}
}

void	ejecute_ra(t_list *node, t_list **from, t_list **to)
{
	t_list	*target;

	target = node -> target;
	if (target -> index <= ft_lstsize((*to)) / 2)
		ejecute_rr(node, target, from, to);
	else
	{
		while (node != (*from))
			ra(from);
		while (target != (*to))
			rrb(to);
	}
}