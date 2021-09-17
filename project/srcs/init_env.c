/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 11:11:13 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*cpy_content_stack(void *src)
{
	return ((void *)new_cell(get_value(src), get_position(src)));
}

static	void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->total_item = 0;
	stack->bigger_elem = MIN_INT;
}

void	init_env(t_env *env, const char **argv, int argc)
{
	env->position_array = NULL;
	env->pa.p1 = MIN_INT;
	env->pa.p2 = MIN_INT;
	env->pb.p1 = MIN_INT;
	env->pb.p2 = MIN_INT;
	init_stack(&(env->b));
	init_stack(&(env->a));
	init_stack(&(env->c_a));
	init_stack(&(env->c_b));
	init_stack(&(env->action_stack));
	init_a(env, argv, argc);
	ft_lstdbcpy(env->a.head, &env->c_a.head, &cpy_content_stack);
	env->c_a.total_item = env->a.total_item;
	env->c_a.bigger_elem = env->a.bigger_elem;
}
