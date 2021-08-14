/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 21:57:32 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *giver, t_stack *taker)
{
	t_list	*giver_node;

	if (giver->head == NULL)
		return ;
	giver_node = giver->head;
	giver->head = giver_node->next;
	ft_lstadd_front(&(taker->head), giver_node);
	giver->total_item--;
	taker->total_item++;
}
