/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:22:54 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 01:07:05 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			exit (1);
		ft_lstadd_front(&(stack->a), ft_lstnew(ft_atoi(av[i])));
			i--;
	}
	if (ft_duplicated (stack->a))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}

void	line_by_line(char *line, t_s **stack)
{
	line = get_next_line(0);
	while (line)
	{
		sort_stack(line, &(*stack));
		free(line);
		line = get_next_line(0);
	}
	free (line);
}

int	main(int ac, char **av)
{
	t_s		*stack;
	int		i;
	char	*line;

	if (ac != 1)
	{
		i = ac - 1;
		stack = malloc(sizeof(t_s));
		stack->a = NULL;
		stack->b = NULL;
		ft_parsing(av, stack, i);
		line_by_line(line, &stack);
		if (stack_sorted(stack->a) && ft_lstsize(stack->b) == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}
