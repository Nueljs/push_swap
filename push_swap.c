/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:13:24 by macerver          #+#    #+#             */
/*   Updated: 2026/01/29 06:25:35 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_list(t_list **nums, char *value)
{
	if (*nums == NULL)
		*nums = ft_lstnew(ft_atoi(value));
	else
		ft_lstadd_back(nums, ft_lstnew(ft_atoi(value)));
}
static void	free_split(char	**arg)
{
	int	i;
	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

static int	split_argv(char *values, t_list **nums)
{
	char	**arg;
	int		j;

	arg = ft_split(values, ' ');
	if (!arg)
		return (0);
	j = -1;
	while (arg[++j])
	{
		if (ft_isnumber(arg[j]))
			fill_list(nums, arg[j]);
		else
			return (0);
	}
	free_split(arg);
	return (1);
}

static int	parse_argv(char **value, t_list **nums)
{
	int		i;
	int		splt;
	
	i = 0;
	while (value[++i])
	{
		if (ft_strchr(value[i], ' '))
		{
			splt = split_argv(value[i], nums);
			if (!splt)
				return (0);
		}
		else if (ft_isnumber(value[i]))
			fill_list(nums, value[i]);
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*nums;

	nums = NULL;
	if (argc > 1)
	{
		if(!parse_argv(argv, &nums))
			return (ft_printf("Error\n"));
		if (check_doubles(nums))
			return (ft_printf("Error\n"));
	}
	else
		ft_printf("Error\n");
	if (nums == NULL)
		ft_printf("Error\n");
	else
	{
		while (nums != NULL)
		{
			ft_printf("%d\n", nums -> value);
			nums = nums -> next;
		}
	}
	return (0);
}
