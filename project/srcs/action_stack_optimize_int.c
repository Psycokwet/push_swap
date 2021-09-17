/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack_optimize_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 19:04:01 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define COUPLE_NONE_FOUND	-1
#define COUPLE_BOTH_FOUND	3
#define COUPLE_A_FOUND		1
#define COUPLE_B_FOUND		2

void	init_couples(t_env *env)
{
	env->couples[0] = (t_couple){ACT_ID_R_, -1, ACT_ID_RR};
	env->couples[1] = (t_couple){ACT_ID_RR_, -1, ACT_ID_RRR};
	env->couples[2] = (t_couple){ACT_ID_S_, -1, ACT_ID_SS};
}

int	test_couple(t_env *env, t_list_double *current, int index)
{
	int	action_code;

	action_code = *(int *)current->content;
	if (env->couples[index].seek + ACT_ID__A == action_code)
	{
		if (env->couples[index].found == COUPLE_B_FOUND)
			env->couples[index].found = COUPLE_BOTH_FOUND;
		else
			env->couples[index].found = COUPLE_A_FOUND;
	}
	else if (env->couples[index].seek + ACT_ID__B == action_code)
	{
		if (env->couples[index].found == COUPLE_A_FOUND)
			env->couples[index].found = COUPLE_BOTH_FOUND;
		else
			env->couples[index].found = COUPLE_B_FOUND;
	}
	else
		return (false);
	return (true);
}

void	try_to_fill_couple(t_env *env, t_list_double *current, int index)
{
	t_list_double	*start;
	t_list_double	*prev;

	start = current;
	if (!current)
		return ;
	while (current && env->couples[index].found != COUPLE_BOTH_FOUND)
	{
		prev = current;
		current = current->next;
		if (!current)
			return ;
		if (test_couple(env, current, index) == false)
			return ;
	}
	if (env->couples[index].found == COUPLE_BOTH_FOUND)
	{
		*(int *)start->content = env->couples[index].replacement;
		env->action_stack.total_item--;
		ft_lstdbcut_next(prev);
		ft_lstdbclear(&current, &free);
	}
}

void	optimise_action_from_node(t_env *env, t_list_double *current)
{
	int	i;

	i = 0;
	while (MAX_COUPLES > i)
	{
		if (test_couple(env, current, i) == true)
		{
			try_to_fill_couple(env, current, i);
			return ;
		}
		i++;
	}
}
