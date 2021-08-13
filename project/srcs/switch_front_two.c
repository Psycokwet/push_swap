/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_front_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 10:56:27 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	switch_front_two(t_stack *stack)
{
	t_list *first_then_second;
	t_list *second_then_first;

	first_then_second = stack->head;
	if(first_then_second == NULL)
		return;
	second_then_first = stack->head->next;
	if(second_then_first == NULL)
		return;
	stack->head = second_then_first->next;
	ft_lstadd_front(&(stack->head), first_then_second);
	ft_lstadd_front(&(stack->head), second_then_first);

	if(first_then_second->next != NULL)
		return;
}
