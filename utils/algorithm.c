/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:40:44 by macerver          #+#    #+#             */
/*   Updated: 2026/02/16 01:25:53 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	ft_printf("b\n");
	if (ft_lstsize((*stack_a)) > 3)
	{
		// int	i;

		// i = 3;
		while (ft_lstsize((*stack_a)) > 3)
			pb(stack_a, stack_b);
	}
	else if(ft_lstsize((*stack_a)) == 2)
		sort_2(stack_a);
	else
		sort_3(stack_a);
}