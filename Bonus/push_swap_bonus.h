/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:23:15 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 02:48:37 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_s
{
	t_stack	*a;
	t_stack	*b;
}	t_s;

// CHECK ARGS

int		ft_isdigit(char *str);
void	limit_int(long int res, int s);
int		ft_atoi(const char	*str);
int		ft_duplicated(t_stack *stack);
int		stack_sorted(t_stack	*stack);

// PARSING

void	ft_parsing(char **av, t_s *stack, int i);

// LINKED LIST UTILS

int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);

// OPERATIONS  S P R RR

void	ft_swap(t_stack	**stack);
void	ft_push(t_stack	**stack1, t_stack	**stack2);
void	ft_rotate(t_stack **stack);
void	*ft_reverse_rotate(t_stack **stack);

// OPEARTIONS SS RR RRR

void	ft_ss(t_s **stack);
void	ft_rr(t_s **stack);
void	ft_rrr(t_s **stack);

// CHECKER UTILS

void	print_error(void);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);

// SORT STACK

void	line_by_line(char *line, t_s **stack);
void	sort_stack(char *line, t_s **s);

#endif