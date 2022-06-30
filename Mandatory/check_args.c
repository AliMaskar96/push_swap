/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:21:17 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 01:10:44 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	limit_int(long int res, int signe)
{
	if ((res > 2147483647 && signe == 1) || (res > 2147483648 && signe == -1))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}	
}

int	ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long int	res;

	i = 0;
	signe = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		limit_int (res, signe);
	}
	return (res * signe);
}

int	stack_sorted(t_stack	*stack)
{
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_duplicated(t_stack	*stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
