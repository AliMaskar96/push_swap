/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:23:10 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/25 15:31:01 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_ss(t_s **stack)
{
	ft_swap(&(*stack)->a);
	ft_swap(&(*stack)->b);
}

void	ft_rr(t_s **stack)
{
	ft_rotate(&(*stack)->a);
	ft_rotate(&(*stack)->b);
}

void	ft_rrr(t_s **stack)
{
	ft_reverse_rotate(&(*stack)->a);
	ft_reverse_rotate(&(*stack)->b);
}
