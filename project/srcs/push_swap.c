/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/10/17 17:56:32 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_env *env)
{
	if (env->total_item < 2)
		return ;
	if (env->total_item == 2)
		return (sort_two(env, env->a, ACT_ID__A, &start_action_ps));
	if (env->total_item == 3)
		return (sort_three(env, env->a, ACT_ID__A, &start_action_ps));
	if (env->total_item == 4)
		return (start_brute_force(env));
	if (env->total_item == 5)
		return (sort_five(env, &start_action_ps));
	init_position_array(env);
	sort_a_to_b(env, env->total_item, &start_action_for_optimization);
	optimise_action_stack(env);
	reset_a_and_b(env);
	execute_action_stack(env, &start_action_ps);
}
