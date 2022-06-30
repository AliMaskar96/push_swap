/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p_r_rr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:23:05 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/27 04:24:47 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_stack	**stack)
{
	int	tmp;

	if (ft_lstsize((*stack)) < 2)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
}

void	ft_push(t_stack	**stack1, t_stack	**stack2)
{
	int		tmp;
	int		i;
	t_stack	*t;

	i = ft_lstsize(*stack1);
	if (i < 1)
		return ;
	tmp = (*stack1)->nbr;
	t = (*stack1)->next;
	free (*stack1);
	*stack1 = t;
	ft_lstadd_front(stack2, ft_lstnew(tmp));
}

void	ft_rotate(t_stack **stack)
{
	int		first;
	t_stack	*tmp;

	if (ft_lstsize((*stack)) < 2)
		return ;
	first = (*stack)->nbr;
	tmp = (*stack)->next;
	free (*stack);
	(*stack) = tmp;
	ft_lstadd_back(stack, ft_lstnew(first));
}

void	*ft_reverse_rotate(t_stack **stack)
{
	t_stack	*head;

	if (ft_lstsize(*stack) < 2)
		return (NULL);
	head = *stack;
	while (head->next->next)
		head = head->next;
	ft_lstadd_front(stack, head->next);
	head->next = NULL;
	return (head);
}
