/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 14:14:59 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list_double	*get_absolute_next(t_stack *stack, t_list_double *elem)
{
	if (!stack || !elem || stack->total_item <= 1)
		return (NULL);
	if (!elem->next)
		return (stack->head);
	return (elem->next);
}
