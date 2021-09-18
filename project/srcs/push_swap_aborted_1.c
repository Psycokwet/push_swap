/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aborted_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/18 21:44:50 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//should replace by a choice rrb or rb depending on proximity?
void	rotate_while_sorted(t_env *env, t_stack *stack, int (*fun)(t_env*, int))
{
	if (stack->head)
		while (get_position(stack->head->content) == 0
			|| (stack->total_item > 1
				&& get_position(get_absolute_prev(stack, stack->head)->content)
				== get_position(stack->head->content) - 1))
			fun(env, ACT_ID_R_ + ACT_ID__A);
}

void	validate_sorted_elem(t_env *env, t_stack *stack, t_list_double *elem)
{
	t_list_double	*prev;

	prev = get_absolute_prev(stack, elem);
	if (!prev)
		return ;
	if (get_is_sorted(prev->content) == true && get_position(prev->content)
		== get_position(elem->content) - 1)
		set_is_sorted(elem->content, true);
}

void	validate_sorted_stack(t_env *env)
{
	t_list_double	*current;

	current = env->a.head;
	while (current)
	{
		if (get_position(current->content) == 0)
			break ;
		current = current->next;
	}
	if (!current)
		return ;
	set_is_sorted(current->content, true);
	while (current)
	{
		validate_sorted_elem(env, &env->a, current);
		current = current->next;
	}
}

void	push_if_sorted(t_env *env, int (*fun)(t_env*, int))
{
	while (env->b.head && (get_position(env->b.head->content) == 0
			|| (env->a.head
				&& ((get_value(env->b.head->content) <= env->pb.p1
						&& (get_position(env->a.tail->content)
							== get_position(env->b.head->content) - 1))
					|| (get_value(env->b.head->content) >= env->pb.p1
						&& (get_position(env->a.head->content)
							== get_position(env->b.head->content) + 1))))))
		fun(env, ACT_ID_P_ + ACT_ID__A);
}

void	b_to_a(t_env *env, int (*fun)(t_env*, int))
{
	find_pivots(env, env->b, &env->pb, env->b.total_item);
	while (env->b.total_item > 0)
	{
		print_both(env);
		validate_sorted_stack(env);
		rotate_while_sorted(env, &env->a, fun);
		push_if_sorted(env, fun);
		fun(env, ACT_ID_R_ + ACT_ID__B);
	}
	rotate_while_sorted(env, &env->a, fun);
	validate_sorted_stack(env);
	print_both(env);
	find_pivots(env, env->a, &env->pa, pivot_size_from_sorted_side(env, env->a));
}
