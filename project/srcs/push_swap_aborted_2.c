/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aborted_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 11:18:23 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_position(t_stack stack)
{
	int				pos;
	t_list_double	*tmp;

	pos = 0;
	tmp = stack.head;
	while (tmp)
	{
		if (get_value(stack.head->content) > get_value(tmp->content))
			++pos;
		tmp = tmp->next;
	}
	return (pos);
}

void	algo(t_env *env, int (*fun)(t_env*, int))
{
	int	mid_value;

	init_position_array(env);
	mid_value = env->position_array[env->total_item / 2];
	while (check_if_all_bigger(env->a, mid_value) == MISC)
	{
		if ((get_value(env->a.head->content)) <= mid_value)
		{
			fun(env, ACT_ID_P_ + ACT_ID__B);
			continue ;
		}
		fun(env, ACT_ID_R_ + ACT_ID__A);
	}
	b_to_a(env, fun);
}
