/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:22:45 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 01:55:17 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_stack(char *line, t_s **s)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_swap(&(*s)->a);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap(&(*s)->b);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_push(&(*s)->b, &(*s)->a);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push(&(*s)->a, &(*s)->b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate(&(*s)->a);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate(&(*s)->b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_reverse_rotate(&(*s)->a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_reverse_rotate(&(*s)->b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss(&(*s));
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(&(*s));
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(&(*s));
	else
		print_error();
}
