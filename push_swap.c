/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:13:24 by macerver          #+#    #+#             */
/*   Updated: 2026/01/22 06:04:14 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int		i;
		t_list	*nums;
		char	**arg;
		
		i = 1;
		nums = NULL;
		while (argv[i])
		{
			if (ft_strchr(argv[i], ' '))
			{
				int	j;

				j = 0;
				arg = ft_split(argv[i], ' ');
				while (arg[j])
				{
					if (ft_isdigit(arg[j]))
					{
						if (!nums)
							nums = ft_lstnew(ft_atoi(arg[j]));
						else
							ft_lstadd_back(&nums, ft_lstnew(ft_atoi(arg[j])));
						j++;
					}
					else
						return (ft_printf("Error\n"));
				}
			}
			else
				if (!nums)//i stay here in this if and i have to make the part when i dont find a space and the params of the program are whitout "" but i had the idea that i have to make another funtio called lst_fill where i can check if i have some node or not and fill based on that.
		}
	}
	else
		ft_printf("Erro");
	return 0;
}