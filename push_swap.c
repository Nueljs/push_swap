/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:13:24 by macerver          #+#    #+#             */
/*   Updated: 2026/01/27 06:38:01 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_list(t_list **nums, char *value)
{
	if (*nums == NULL)
		*nums = ft_lstnew(ft_atoi(value));
	else
		ft_lstadd_back(nums, ft_lstnew(ft_atoi(value)));
}

int	parse_argv(char **value, t_list **nums)
{
	char	**arg;
	int		i;
	int		j;
	
	i = 0;
	while (value[++i])
	{
		if (ft_strchr(value[i], ' '))
		{
			j = -1;
			arg = ft_split(value[i], ' ');
			while (arg[++j])
			{
				if (ft_isnumber(arg[j]))
					fill_list(nums, arg[j]);
				else
					return (0);
			}
		}
		else if (ft_isnumber(value[i]))
			fill_list(nums, value[i]);
		else
			return (0);
	}
	return (1);
}
int	check_doubles(t_list **nums)
{
	int		aux;
	t_list	*list_aux;
	
	list_aux = *nums;
	while((*nums) != NULL)
	{
		aux	= (*nums) -> value;
		list_aux = (*nums) -> next;
		while (((*nums) != NULL) && (aux != (*nums) -> value))
			(*nums) = (*nums) -> next;
		if (())
		if (aux == (*nums) -> value)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*nums;

	nums = NULL;
	if (argc > 1)
	{
		if(!parse_argv(argv, &nums))
			return (ft_printf("Error\n"));
		if (check_doubles(&nums))
			return (ft_printf("Error\n"));
	}
	else
		ft_printf("Error\n");
	
	if (!nums)
		ft_printf("Error\n");
	else
	{
		while (nums -> next != NULL)
		{
			ft_printf("%d\n", nums -> value);
			nums = nums -> next;
			if (nums -> next == NULL)
				ft_printf("%d\n", nums -> value);
		}
	}
	return (0);
}