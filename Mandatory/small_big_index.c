/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_big_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:22:11 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 02:31:20 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	give_smallest_index(t_stack *stack)
{
	int	i;
	int	nbr;
	int	index;

	i = 0;
	index = 0;
	nbr = stack->nbr;
	while (stack)
	{
		if (nbr > stack->nbr)
		{
			nbr = stack->nbr;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int	give_biggest_index(t_stack *stack)
{
	int	i;
	int	nbr;
	int	index;

	i = 0;
	index = 0;
	nbr = stack->nbr;
	while (stack)
	{
		if (nbr < stack->nbr)
		{
			nbr = stack->nbr;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}
