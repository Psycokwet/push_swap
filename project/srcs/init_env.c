/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/31 11:40:02 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		*cpy_content_stack(void *src)
{
	int *value = (int*)malloc(sizeof(int));
	*value = *(int *)src;
	return ((void *)value);
}

void	init_env(t_env *env, const char **argv, int argc)
{
	env->position_array = NULL;
	env->pa.p1 = MIN_INT;
	env->pa.p2 = MIN_INT;
	env->pb.p1 = MIN_INT;
	env->pb.p2 = MIN_INT;
	env->b.head = NULL;
	env->b.tail = NULL;
	env->b.total_item = 0;
	env->b.bigger_elem = MIN_INT;
	env->c_b.head = NULL;
	env->c_b.tail = NULL;
	env->c_b.total_item = 0;
	env->c_b.bigger_elem = MIN_INT;
	env->c_a.head = NULL;
	env->c_a.tail = NULL;
	env->c_a.total_item = 0;
	env->c_a.bigger_elem = MIN_INT;
	env->action_stack.head = NULL;
	env->action_stack.tail = NULL;
	env->action_stack.total_item = 0;
	env->a.bigger_elem = MIN_INT;
	env->a.tail = NULL;
	init_a(env, argv, argc);
	ft_lstdbcpy(env->a.head, &env->c_a.head, &cpy_content_stack);
	env->c_a.total_item = env->a.total_item;
	env->c_a.bigger_elem = env->a.bigger_elem;
}
