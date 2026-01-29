/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 05:58:38 by macerver          #+#    #+#             */
/*   Updated: 2026/01/29 05:59:07 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_list *nums)
{
	int		aux;
	t_list	*list_aux;
	
	list_aux = nums;
	while(nums != NULL)
	{
		aux  = nums -> value;
		list_aux = nums -> next;
		if (list_aux == NULL)
			return 0;
		while ((list_aux != NULL) && (aux != list_aux -> value))
			list_aux = list_aux -> next;
		if (list_aux == NULL)
		{
			nums = nums -> next;
			continue ;
		}
		if (aux == list_aux -> value)
			return (1);
	}
	return (0);
}