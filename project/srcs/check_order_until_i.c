/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order_until_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/31 17:40:31 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_order_int(t_list_double *lst, int prev, int i)
{
	if (!lst || i == 0)
		return (ORDERED);
	if (prev >= *(int *)lst->content)
		return (NOT_ORDERED);
	return (check_order_int(lst->next, *(int *)lst->content, i - 1));
}

int	check_order_until_i(t_stack stack, int i)
{
	if (stack.head)
		return (check_order_int(stack.head, MIN_INT, i));
	return (ORDERED);
}
