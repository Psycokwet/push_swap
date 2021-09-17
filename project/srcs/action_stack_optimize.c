/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack_optimize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 19:04:09 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	optimise_action_stack(t_env *env)
{
	t_list_double	*current;

	if (env->action_stack.total_item < 12)
		return ;
	current = env->action_stack.head;
	while (current)
	{
		init_couples(env);
		optimise_action_from_node(env, current);
		current = current->next;
	}
}

void	execute_action_stack_int(t_env *env, t_list_double *action,
int (*fun)(t_env*, int))
{
	if (!action || !fun)
		return ;
	(*fun)(env, *(int *)action->content);
	execute_action_stack_int(env, action->next, fun);
}

void	execute_action_stack(t_env *env, int (*fun)(t_env*, int))
{
	execute_action_stack_int(env, env->action_stack.head, fun);
}
