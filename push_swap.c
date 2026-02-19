/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:13:24 by macerver          #+#    #+#             */
/*   Updated: 2026/02/18 11:29:59 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_list(t_list **stack_a, char *value)
{
	if (*stack_a == NULL)
		*stack_a = ft_lstnew(ft_atoi(value));
	else
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(value)));
}

static void	free_split(char	**arg)
{
	int	i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

static int	split_argv(char *values, t_list **stack_a)
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
			fill_list(stack_a, arg[j]);
		else
			return (0);
	}
	free_split(arg);
	return (1);
}

static int	parse_argv(char **value, t_list **stack_a)
{
	int		i;
	int		splt;

	i = 0;
	while (value[++i])
	{
		if (ft_strchr(value[i], ' '))
		{
			splt = split_argv(value[i], stack_a);
			if (!splt)
				return (0);
		}
		else if (ft_isnumber(value[i]))
			fill_list(stack_a, value[i]);
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (!parse_argv(argv, &stack_a))
			return (ft_printf("Error\n"));
		if (check_doubles(stack_a))
			return (ft_printf("Error\n"));
	}
	else
		ft_printf("Error\n");
	ft_printf("a\n");
	algorithm(&stack_a, &stack_b);
	if (stack_a == NULL)
		ft_printf("Error\n");
	else
	{
		while (stack_a != NULL)
		{
			ft_printf("%d\n", stack_a -> value);
			stack_a = stack_a -> next;
		}
	}
	return (0);
}
