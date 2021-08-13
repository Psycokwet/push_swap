/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 10:06:50 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_env *env)
{
	t_list *first_then_second;
	t_list *second_then_first;

	first_then_second = env->a.head;
	if(first_then_second == NULL)
		return;
	second_then_first = env->a.head->next;
	if(second_then_first == NULL)
		return;

	ft_lstadd_front(&(env->a.head), first_then_second);
	ft_lstadd_front(&(env->a.head), second_then_first);

	if(first_then_second->next != NULL)
		return;
	env->a.tail = first_then_second;
}
