/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_front_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/14 23:02:05 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	switch_front_two(t_stack *stack)
{
	t_list	*first_then_second;
	t_list	*second_then_first;

	first_then_second = stack->head;
	if (first_then_second == NULL)
		return (NO_ACTION_DONE);
	second_then_first = stack->head->next;
	if (second_then_first == NULL)
		return (NO_ACTION_DONE);
	stack->head = second_then_first->next;
	ft_lstadd_front(&(stack->head), first_then_second);
	ft_lstadd_front(&(stack->head), second_then_first);
	if (first_then_second->next != NULL)
		return (NO_ACTION_DONE);
	return (ACTION_DONE);
}
