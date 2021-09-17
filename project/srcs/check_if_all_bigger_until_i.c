/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_all_bigger_until_i.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 10:57:06 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_if_all_bigger_int(t_list_double *lst, int threshold, int i)
{
	if (!lst || i == 0)
		return (ONLY_BIGGER);
	if (get_value(lst->content) < threshold)
		return (MISC);
	return (check_if_all_bigger_int(lst->next, threshold, i - 1));
}

int	check_if_all_bigger_until_i(t_stack stack, int threshold, int i)
{
	if (stack.head)
		return (check_if_all_bigger_int(stack.head, threshold, i));
	return (ONLY_BIGGER);
}
