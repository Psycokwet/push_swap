/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_front_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 10:56:10 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	switch_front_two(t_stack *stack)
{
	t_list_double	*first_then_second;
	t_list_double	*second_then_first;

	first_then_second = stack->head;
	if (first_then_second == NULL)
		return (NO_ACTION_DONE);
	second_then_first = stack->head->next;
	if (second_then_first == NULL)
		return (NO_ACTION_DONE);
	stack->head = second_then_first->next;
	ft_lstdbadd_front(&(stack->head), first_then_second);
	ft_lstdbadd_front(&(stack->head), second_then_first);
	second_then_first->prev = NULL;
	first_then_second->prev = second_then_first;
	return (ACTION_DONE);
}
