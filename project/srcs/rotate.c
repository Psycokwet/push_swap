/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/30 17:00:05 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_stack *stack)
{
	t_list_double	*first_then_last;

	if (!stack->head)
		return (NO_ACTION_DONE);
	if (stack->total_item <= 1)
		return (NO_ACTION_DONE);
	if (stack->total_item == 2)
		return (switch_front_two(stack));
	first_then_last = stack->head;
	stack->head = first_then_last->next;
	first_then_last->next = NULL;
	ft_lstdbadd_back(&stack->head, first_then_last);
	first_then_last->prev = stack->tail;
	stack->tail = first_then_last;
	stack->head->prev = NULL;
	return (ACTION_DONE);
}
