/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack_brut_force.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 09:44:07 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	start_brute_force(t_env *env)
{
	int	i;

	i = 0;
	while (env->action_stack.total_item < 15)
	{
		upgrade_to_next_possibility(env);
		execute_action_stack(env, &start_action_ps_silent);
		if (env->b.head == NULL && check_order(env->a) == ORDERED)
		{
			reset_a_and_b(env);
			execute_action_stack(env, &start_action_ps);
			return ;
		}
		reset_a_and_b(env);
		i++;
	}
}

#define STARTED 0
#define MAXED_OUT_TILL_NOW 1
#define NOT_MAXED_OUT 2
#define ADD_NEW_ACTION 3
#define NEXT_IS_UPGRADED 4
#define STOP_UPGRADE 5

int	upgrade_to_next_possibility_int_has_no_next(t_env *env,
t_list_double *action, int state)
{
	if (*(int *)action->content == ACT_ID_RRR
		&& state == MAXED_OUT_TILL_NOW)
	{
		add_back_action_stack(env, 0);
		*(int *)action->content = 0;
		return (ADD_NEW_ACTION);
	}
	else if (*(int *)action->content == ACT_ID_RRR)
	{
		*(int *)action->content = 0;
		return (NEXT_IS_UPGRADED);
	}
	else
	{
		(*(int *)action->content)++;
		return (STOP_UPGRADE);
	}
}

int	upgrade_to_next_possibility_int_after_rec(t_env *env,
t_list_double *action, int ret)
{
	if (ret == ADD_NEW_ACTION)
	{
		*(int *)action->content = 0;
		return (ADD_NEW_ACTION);
	}
	else if (ret == NEXT_IS_UPGRADED && *(int *)action->content == ACT_ID_RRR)
	{
		*(int *)action->content = 0;
		return (NEXT_IS_UPGRADED);
	}
	else if (ret == NEXT_IS_UPGRADED && *(int *)action->content != ACT_ID_RRR)
	{
		(*(int *)action->content)++;
		return (STOP_UPGRADE);
	}
	return (STOP_UPGRADE);
}

int	upgrade_to_next_possibility_int(t_env *env, t_list_double *action,
int state)
{
	if (*(int *)action->content == ACT_ID_RRR && (state == STARTED
			|| state == MAXED_OUT_TILL_NOW))
		state = MAXED_OUT_TILL_NOW;
	else
		state = NOT_MAXED_OUT;
	if (!action->next)
		return (upgrade_to_next_possibility_int_has_no_next(env, action,
				state));
	return (upgrade_to_next_possibility_int_after_rec(env, action,
			upgrade_to_next_possibility_int(env, action->next, state)));
}

void	upgrade_to_next_possibility(t_env *env)
{
	if (!env->action_stack.head)
		add_back_action_stack(env, 0);
	else
		upgrade_to_next_possibility_int(env, env->action_stack.head, STARTED);
}
