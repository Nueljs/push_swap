/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:35:55 by macerver          #+#    #+#             */
/*   Updated: 2026/02/25 18:23:53 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if ((ft_lstsize((*from)) == 1))
	{
		tmp = *from;
		*from = NULL;
		tmp -> next = *to;
		*to = tmp;
	}
	else
	{
		tmp = *from;
		*from = tmp -> next;
		tmp -> next = *to;
		*to = tmp;
	}
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}
