/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:21:46 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 01:12:10 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing(char **av, t_s *stack, int i)
{
	while (i > 0)
	{
		if (av[i][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		if (!ft_isdigit(av[i]))
			exit(1);
		ft_lstadd_front(&(stack->a), ft_lstnew(ft_atoi(av[i])));
			i--;
	}
	if (ft_duplicated (stack->a))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (stack_sorted(stack->a))
		exit(1);
}

void	smallsort_bigsort(t_s **stack, int ac)
{
	if (ft_lstsize((*stack)->a) <= 15)
		small_sort(stack);
	else
		big_sort(stack);
}

int	main(int ac, char **av)
{
	t_s		*stack;
	int		i;

	if (ac != 1)
	{
		i = ac - 1;
		stack = malloc(sizeof(t_s));
		if (!stack)
			return (1);
		stack->a = NULL;
		stack->b = NULL;
		ft_parsing(av, stack, i);
		smallsort_bigsort(&stack, ac);
	}
	return (0);
}

//system("leaks push_swap");