/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 05:40:24 by macerver          #+#    #+#             */
/*   Updated: 2026/02/06 05:58:53 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list *aux;

	aux = *stack;
	while (aux -> next != NULL)
		aux = aux -> next;
	aux -> next = *stack;
	aux = aux -> next;
	*stack = (*stack) -> next;
	aux -> next = NULL;
}