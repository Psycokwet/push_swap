/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_all_bigger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 10:55:04 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_if_all_bigger_int(t_list_double *lst, int threshold)
{
	if (!lst)
		return (ONLY_BIGGER);
	if (get_value(lst->content) < threshold)
		return (MISC);
	return (check_if_all_bigger_int(lst->next, threshold));
}

int	check_if_all_bigger(t_stack stack, int threshold)
{
	if (stack.head)
		return (check_if_all_bigger_int(stack.head, threshold));
	return (ONLY_BIGGER);
}
