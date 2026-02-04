/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:35:55 by macerver          #+#    #+#             */
/*   Updated: 2026/02/04 19:53:26 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	tmp = *from;
	*from = tmp -> next;
	tmp -> next = *to;
	*to = tmp;
}