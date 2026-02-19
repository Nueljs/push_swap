/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:55:42 by macerver          #+#    #+#             */
/*   Updated: 2026/02/18 12:44:50 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

///////
//UTILS
///////

int		ft_printf(const char *str, ...);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_isnumber(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *str);
int		check_doubles(t_list *nums);
void	sort_3(t_list **stack);
void	sort_2(t_list **stack);
void	algorithm(t_list **stack_a, t_list **stack_b);

//UTILS LIST

t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

//////////////
//INSTRUCTIONS
//////////////

//SWAP
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

//PUSH
void	pb(t_list **stack_b, t_list **stack_a);
void	pa(t_list **stack_a, t_list **stack_b);
void	push(t_list **from, t_list **to);

//REVERSE ROTATE
void	rrotate(t_list **stack);
void	rrb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrr(t_list **stack_a, t_list **stack_b);

//ROTATE
void	rotate(t_list **stack);
void	rb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rr(t_list **stack_a, t_list **stack_b);

#endif