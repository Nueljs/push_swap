/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:55:42 by macerver          #+#    #+#             */
/*   Updated: 2026/01/29 05:59:24 by macerver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#  define PUSH SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
} t_list;

int		ft_printf(const char *str, ...);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int value);
int		ft_isnumber(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *str);
int		check_doubles(t_list *nums);

#endif