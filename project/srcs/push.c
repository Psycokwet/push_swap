/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/27 15:04:41 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_stack *giver, t_stack *taker)
{
	t_list_double	*giver_node;

	if (giver->head == NULL)
		return (NO_ACTION_DONE);

	if (taker->total_item == 1)
		taker->tail = taker->head;
	giver_node = giver->head;
	giver->head = giver_node->next;
	ft_lstdbadd_front(&(taker->head), giver_node);
	giver->total_item--;
	if (giver->total_item <= 1)
		giver->tail = giver->head;
	taker->total_item++;
	if (taker->total_item == 1)
		taker->tail = taker->head;
	if (giver->total_item >= 1)
		giver->head->prev = NULL;
	return (ACTION_DONE);
}
