/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:21:10 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 01:59:54 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_exist_in_b(int nbr, t_stack *stack)
{
	while (stack)
	{
		if (nbr == stack->nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	last_stack_a(t_stack *stack_a)
{
	while (stack_a)
	{
		if (!stack_a->next)
			return (stack_a->nbr);
		stack_a = stack_a->next;
	}
	return (-1);
}

void	ft_help1(int *down, t_s **s)
{
	if (*down == 0 || (*s)->b->nbr > last_stack_a((*s)->a))
	{
		push(&((*s)->b), &((*s)->a), 'a');
		rotate(&(*s)->a, 'a');
		(*down)++;
	}
	else
	{
		if (give_biggest_index((*s)->b) < ft_lstsize((*s)->b) / 2)
			rotate(&(*s)->b, 'b');
		else
			reverse_rotate(&(*s)->b, 'b');
	}
}

void	ft_help2(int *tab, int *size, t_s **s, int *down)
{
	if (check_if_exist_in_b(tab[*size], (*s)->b))
	{
		if (tab[*size] == (*s)->b->nbr)
		{	
			push(&((*s)->b), &((*s)->a), 'a');
			(*size)--;
		}
		else
			ft_help1(down, s);
	}
	else
	{
		reverse_rotate(&(*s)->a, 'a');
		(*down)--;
		(*size)--;
	}	
}

void	great_work(t_s **s, t_help *help, int *tab)
{
	int	size;
	int	down;

	down = 0;
	size = help->size - 1;
	push_chunks_to_b(*s, tab, help);
	while (ft_lstsize((*s)->b) > 0)
	{
		ft_help2(tab, &size, s, &down);
	}
	while (down > 0)
	{
		reverse_rotate(&(*s)->a, 'a');
		down--;
	}
}
