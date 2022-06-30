/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:21:52 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 01:59:17 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

typedef struct s_help
{
	t_s	*s;
	int	*tab;
	int	size;
	int	mid;
	int	min;
	int	max;
	int	chunk;
}	t_help;

// CHECK ARGS

int		ft_isdigit(char *str);
void	limit_int(long int res, int s);
int		ft_atoi(const char *str);
int		stack_sorted(t_stack *stack);
int		ft_duplicated(t_stack *stack);

// PARSING

void	ft_parsing(char **av, t_s *stack, int i);

// LINKED LIST UTILS

int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);

// OPERATIONS  S P R RR

void	swap(t_stack **stack, char a);
void	push(t_stack **stack1, t_stack **stack2, char a);
void	rotate(t_stack **stack, char a);
void	*reverse_rotate(t_stack **stack, char c);

// OPERATIONS SS RR RRR

void	ss(t_s **stack);
void	rr(t_s **stack);
void	rrr(t_s **stack);

// PUSH SWAP UTILS

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

// SMALL INDEX & BIG INDEX

int		give_smallest_index(t_stack *stack);
int		give_biggest_index(t_stack *stack);

// SMALL SORT ( 0 --> 2 --> 3 --> 15 )

void	sort_2(t_stack **stack);
void	sort_3(t_stack **s);
void	sort_3_to_15(t_s **stack);
void	small_sort(t_s **s);

// BIG SORT ( 15 ----> 500)

int		*convert_stack_to_tab(t_stack *stack, int size);
void	bubble_sort_tab(t_help *help, int size);
void	chunks_init(t_stack *stack, t_help *help);
int		check_if_exist_in_chunk(int nbr, t_help *help, int *tab);
int		check_if_exist_in_b(int nbr, t_stack *stack);
void	push_chunks_to_b(t_s *s, int *tab, t_help *help);
int		last_stack_a(t_stack *stack_a);
void	ft_help1(int *d, t_s **s);
void	ft_help2(int *tab, int *size, t_s **s, int *d);
void	great_work(t_s **s, t_help *help, int *tab);
void	big_sort(t_s **s);

// SMALL SORT & BIG SORT

void	smallsort_bigsort(t_s **stack, int ac);

#endif