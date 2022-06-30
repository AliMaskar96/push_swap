/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:22:00 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 02:32:13 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_s **s)
{
	if (ft_lstsize((*s)->a) == 2)
		sort_2(&(*s)->a);
	else if (ft_lstsize((*s)->a) == 3)
		sort_3(&(*s)->a);
	else
		sort_3_to_15(s);
}

void	sort_2(t_stack **stack)
{
	int	i;

	i = ft_lstsize(*stack);
	if (i == 2)
		swap((stack), 'a');
}

void	sort_3(t_stack **s)
{
	int	i;

	i = ft_lstsize(*s);
	if (i == 3)
	{
		if ((*s)->nbr > (*s)->next->nbr && (*s)->nbr > (*s)->next->next->nbr)
			rotate(s, 'a');
		else if ((*s)->next->nbr > (*s)->nbr
			&& (*s)->next->nbr > (*s)->next->next->nbr)
			reverse_rotate(s, 'a');
		if ((*s)->nbr > (*s)->next->nbr)
			swap((s), 'a');
	}
}

void	sort_3_to_15(t_s **stack)
{
	int	i;
	int	size;

	size = ft_lstsize((*stack)->a);
	while (size > 3)
	{
		i = give_smallest_index((*stack)->a);
		if (i == 0)
		{
			push(&(*stack)->a, &(*stack)->b, 'b');
			size--;
		}
		else
		{
			if (i > ft_lstsize((*stack)->a) / 2)
				reverse_rotate(&(*stack)->a, 'a');
			else
				rotate(&(*stack)->a, 'a');
		}
	}
	sort_3(&(*stack)->a);
	while ((*stack)->b)
		push (&(*stack)->b, &(*stack)->a, 'a');
}
