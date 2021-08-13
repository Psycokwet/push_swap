/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 15:54:20 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_order_int(t_list *lst, int prev)
{
	if (!lst)
		return (ORDERED);
	if (prev >= *(int *)lst->content)
		return (NOT_ORDERED);
	return (check_order_int(lst->next, *(int *)lst->content));
}

int	check_order(t_stack stack)
{
	if (stack.head)
		return (check_order_int(stack.head, MIN_INT));
	return (ORDERED);
}
