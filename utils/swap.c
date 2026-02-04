/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:49:48 by macerver          #+#    #+#             */
/*   Updated: 2026/02/04 19:15:20 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*node2;
	t_list	*node3;
	
	node2 = (*stack) -> next;
	node3 = node2 -> next;
	node2 -> next = (*stack);
	*stack = node2;
	node2 = (*stack) -> next;
	node2 -> next = node3;
}