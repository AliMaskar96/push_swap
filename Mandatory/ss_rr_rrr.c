/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:21:38 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/27 05:42:48 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_s **stack)
{
	swap(&(*stack)->a, 0);
	swap(&(*stack)->b, 0);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_s **stack)
{
	rotate(&(*stack)->a, 0);
	rotate(&(*stack)->b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_s **stack)
{
	reverse_rotate(&(*stack)->a, 0);
	reverse_rotate(&(*stack)->b, 0);
	ft_putstr_fd("rrr\n", 1);
}
