/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 11:41:34 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define NOT_FOUND	0
#define FOUND_LAST	1
#define SET_LAST	2

static int	ft_lst_before_last_int(t_list *lst, t_list **before_last)
{
	int	result;

	if (lst->next)
	{
		result = ft_lst_before_last_int(lst->next, before_last);
		if (result == FOUND_LAST)
		{
			*before_last = lst;
			return (SET_LAST);
		}
		if (result == SET_LAST)
			return (SET_LAST);
		return (NOT_FOUND);
	}
	return (FOUND_LAST);
}

static t_list	*ft_lst_before_last(t_list *lst)
{
	t_list	*before_last;

	if (lst)
	{
		ft_lst_before_last_int(lst, &before_last);
		return (before_last);
	}
	return (NULL);
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*last_then_first;
	t_list	*before_last;

	if (!stack->head)
		return ;
	before_last = ft_lst_before_last(stack->head);
	if (!before_last)
		return ;
	last_then_first = before_last->next;
	before_last->next = NULL;
	ft_lstadd_front(&stack->head, last_then_first);
}
