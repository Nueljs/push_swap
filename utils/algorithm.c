/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:40:44 by macerver          #+#    #+#             */
/*   Updated: 2026/02/13 17:29:15 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_list **stack_a)
{
	if (ft_lstsize((*stack_a)) > 3)
	{
		ft_printf("mayor de 3");
	}
	else
		sort_3(stack_a);
}