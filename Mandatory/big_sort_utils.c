/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:22:06 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 02:17:08 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_tab(t_help *help, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (i + j < size)
		{
			if (help->tab[i] > help->tab[i + j])
			{
				tmp = help->tab[i];
				help->tab[i] = help->tab[i + j];
				help->tab[i + j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*convert_stack_to_tab(t_stack *stack, int size)
{
	t_help	help;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	help.tab = malloc(ft_lstsize(stack) * sizeof(int));
	if (!help.tab)
		return (NULL);
	while (stack)
	{
		help.tab[i] = stack->nbr;
		i++;
		stack = stack->next;
	}
	bubble_sort_tab(&help, size);
	return (help.tab);
}

void	chunks_init(t_stack *stack, t_help *help)
{
	static int	size;

	size = ft_lstsize(stack);
	help->mid = size / 2;
	if (ft_lstsize(stack) <= 100)
	{
		help->chunk = size / 10;
	}
	else
		help->chunk = size / 20;
	help->min = (help->mid) - (help->chunk);
	help->max = (help->mid) + (help->chunk);
}

int	check_if_exist_in_chunk(int nbr, t_help *help, int *tab)
{
	int	i;

	i = help->max;
	while (help->min <= i)
	{
		if (tab[i] == nbr)
			return (1);
	i--;
	}
	return (0);
}

void	push_chunks_to_b(t_s *s, int *tab, t_help *help)
{
	chunks_init((*s).a, help);
	while (s->a)
	{
		if (help->min < 0 || help->max > help->size)
		{
			help->min = 0;
			help->max = help->size;
		}
		if (check_if_exist_in_chunk(s->a->nbr, help, tab))
		{
			push(&(s->a), &(s->b), 'b');
			if (s->b->nbr <= tab[help->size / 2])
				rotate(&(s->b), 'b');
		}
		else
			rotate(&(s->a), 'a');
		if (ft_lstsize(s->b) >= (help->max - help->min))
		{
			help->min -= help->chunk;
			help->max += help->chunk;
		}
	}
}
