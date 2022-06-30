/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:20:48 by aait-mas          #+#    #+#             */
/*   Updated: 2022/06/28 02:18:18 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_s **s)
{
	t_help	help;
	int		*tab;

	help.size = ft_lstsize((*s)->a);
	tab = convert_stack_to_tab((*s)->a, help.size);
	if (help.size > 15)
		great_work(s, &help, tab);
	free(tab);
}
