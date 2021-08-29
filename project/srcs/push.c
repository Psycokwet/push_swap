/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/29 16:38:56 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define FOUND 0
#define NOT_FOUND 1
#define ERROR 2

static int		cmp_if_bigger(void*seek, void* current)
{
	int tmp_current;

	tmp_current = get_value(current);
	if (get_value(seek) < tmp_current)
	{
		((t_cell*)seek)->value = tmp_current;
		return (FOUND);
	}
	return (NOT_FOUND);
}

void	find_new_bigger_elem(t_stack *stack)
{
	t_list_double	*found;
	int				bigger_int;
	int				result;

	result = -1;
	bigger_int = MIN_INT;
	found = NULL;
	result = ft_lstdbfind_best_match(stack->head, &found, &bigger_int, &cmp_if_bigger);
	if (result == FOUND)
		stack->bigger_elem = bigger_int;
	else
		stack->bigger_elem = MIN_INT;
	//else	 ERROR
}

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
	{
		taker->tail = taker->head;
		taker->bigger_elem = get_value(taker->tail->content);
	}
	if (giver->total_item >= 1)
		giver->head->prev = NULL;
	if (taker->bigger_elem < get_value(giver_node->content))
		taker->bigger_elem = get_value(giver_node->content);
	if (get_value(giver_node->content) == giver->bigger_elem)
		find_new_bigger_elem(giver);
	return (ACTION_DONE);
}
