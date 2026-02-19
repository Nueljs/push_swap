/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 05:40:24 by macerver          #+#    #+#             */
/*   Updated: 2026/02/18 12:13:56 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)//The first element becomes the last one
{
	t_list	*aux;
	t_list	*aux2;

	aux = (*stack)-> next;
	aux2 = aux -> next;
	while (aux2 -> next != NULL)
		aux2 = aux2 -> next;
	aux2 -> next = *stack;
	(*stack)-> next = NULL;
	*stack = aux;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
