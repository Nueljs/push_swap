/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:50:09 by macerver          #+#    #+#             */
/*   Updated: 2026/02/10 11:52:35 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int	value)
{
	t_list	*nodo;

	nodo = malloc(sizeof(t_list));
	if (!nodo)
		return (NULL);
	nodo -> value = value;
	nodo -> next = NULL;
	return (nodo);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = *lst;
	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	while (aux -> next != NULL)
		aux = aux -> next;
	aux -> next = new;
}