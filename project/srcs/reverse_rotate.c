/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/27 11:21:28 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define NOT_FOUND	0
#define FOUND_LAST	1
#define SET_LAST	2

static int	ft_lstdb_before_last_int(t_list_double *lst, t_list_double **before_last)
{
	int	result;

	if (lst->next)
	{
		result = ft_lstdb_before_last_int(lst->next, before_last);
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

static t_list_double	*ft_lstdb_before_last(t_list_double *lst)
{
	t_list_double	*before_last;

	if (lst)
	{
		ft_lstdb_before_last_int(lst, &before_last);
		return (before_last);
	}
	return (NULL);
}

int	reverse_rotate(t_stack *stack)
{
	t_list_double	*last_then_first;
	t_list_double	*before_last;

	if (!stack->head || !stack->head->next)
		return (NO_ACTION_DONE);
	before_last = ft_lstdb_before_last(stack->head);
	if (!before_last)
		return (NO_ACTION_DONE);
	last_then_first = before_last->next;
	before_last->next = NULL;
	ft_lstdbadd_front(&stack->head, last_then_first);
	return (ACTION_DONE);
}
