/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:21:25 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 02:23:59 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	new->next = NULL;
	new->prev = NULL;
	new->nbr = content;
	return (new);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		exit(1);
	if (*lst)
	{
		last = ft_lstlast(*lst);
		new->next = NULL;
		last->next = new;
		new->prev = last;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
