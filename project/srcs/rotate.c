/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/27 11:21:57 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_stack *stack)
{
	t_list_double	*first_then_last;

	if (!stack->head)
		return (NO_ACTION_DONE);
	first_then_last = stack->head;
	if (!first_then_last->next)
		return (NO_ACTION_DONE);
	stack->head = first_then_last->next;
	first_then_last->next = NULL;
	ft_lstdbadd_back(&stack->head, first_then_last);
	return (ACTION_DONE);
}
