/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:25:29 by macerver          #+#    #+#             */
/*   Updated: 2026/02/10 12:26:28 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
		if (nptr[i] == '+' || nptr[i] == '-')
			return (0);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

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