/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:13:24 by macerver          #+#    #+#             */
/*   Updated: 2026/01/24 14:38:46 by macerver         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		i;
	t_list	*nums;
	char	**arg;
	int		j;

	i = 1;
	nums = NULL;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_strchr(argv[i], ' '))
			{
				j = 0;
				arg = ft_split(argv[i], ' ');
				while (arg[j])
				{
					if (ft_isdigit(arg[j]))
					{
						fill_list(&nums, arg[j]);
						j++;
					}
					else
						return (ft_printf("Error\n"));
				}
			}
			else
				fill_list(&nums, argv[i]);
			i++;
		}
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
		}
	}
	return (0);
}
