/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p_r_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:21:33 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 02:29:15 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack	**stack, char c)
{
	int	tmp;

	if (ft_lstsize((*stack)) < 2)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	push(t_stack	**stack1, t_stack	**stack2, char c)
{
	int		tmp;
	int		i;
	t_stack	*s;

	i = ft_lstsize(*stack1);
	if (i < 1)
		return ;
	tmp = (*stack1)->nbr;
	s = (*stack1)->next;
	free (*stack1);
	*stack1 = s;
	ft_lstadd_front(stack2, ft_lstnew(tmp));
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	int		first;

	if (ft_lstsize((*stack)) < 2)
		return ;
	first = (*stack)->nbr;
	tmp = (*stack)->next;
	free (*stack);
	(*stack) = tmp;
	ft_lstadd_back(stack, ft_lstnew(first));
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	*reverse_rotate(t_stack **stack, char c)
{
	t_stack	*head;

	if (ft_lstsize(*stack) < 2)
		return (NULL);
	head = *stack;
	while (head->next->next)
		head = head->next;
	ft_lstadd_front(stack, head->next);
	head->next = NULL;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	return (head);
}
