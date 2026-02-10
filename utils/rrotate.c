/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:07:40 by macerver          #+#    #+#             */
/*   Updated: 2026/02/10 11:58:17 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_list **stack)
{
	t_list	*aux;
	t_list	*prev;

	aux = *stack;
	while (aux -> next != NULL)
	{	
		prev = aux;
		aux = aux -> next;
		if (aux -> next == NULL)
			prev -> next = NULL;
	}
	aux -> next = *stack;
	*stack = aux;
}

void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}