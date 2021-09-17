/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 15:25:41 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rreverse(t_env *env, int ra_cnt, int rb_cnt, int (*fun)(t_env *, int))
{
	int	i;

	i = 0;
	while (i < ra_cnt && i < rb_cnt)
	{
		fun(env, ACT_ID_RRR);
		++i;
	}
	while (i < ra_cnt)
	{
		fun(env, ACT_ID_RR_ + ACT_ID__A);
		++i;
	}
	while (i < rb_cnt)
	{
		fun(env, ACT_ID_RR_ + ACT_ID__B);
		++i;
	}
}

void	sort_b_up_to_2(t_env *env, int cnt, int (*fun)(t_env *, int))
{
	if (cnt == 1)
	{
		fun(env, ACT_ID_P_ + ACT_ID__A);
		return ;
	}
	else if (cnt != 2)
		return ;
	if (get_value(env->b.head->content) > get_value(env->b.head->next->content))
	{
		fun(env, ACT_ID_P_ + ACT_ID__A);
		fun(env, ACT_ID_P_ + ACT_ID__A);
	}
	else
	{
		fun(env, ACT_ID_S_ + ACT_ID__B);
		fun(env, ACT_ID_P_ + ACT_ID__A);
		fun(env, ACT_ID_P_ + ACT_ID__A);
	}
}

#define RA	0
#define RB	1
#define P	2

void	sort_b_to_a(t_env *env, int cnt, int (*fun)(t_env *, int))
{
	int	counters[3];
	int	pivots[2];

	ft_memset(counters, 0, sizeof(int) * 3);
	if (cnt <= 2)
		return (sort_b_up_to_2(env, cnt, fun));
	find_pivot(env, env->b, pivots, cnt);
	while (cnt--)
	{
		if (get_value(env->b.head->content) < pivots[0])
			counters[RB] += fun(env, ACT_ID_R_ + ACT_ID__B);
		else
		{
			counters[P] += fun(env, ACT_ID_P_ + ACT_ID__A);
			if (get_value(env->a.head->content) < pivots[1])
				counters[RA] += fun(env, ACT_ID_R_ + ACT_ID__A);
		}
	}
	sort_a_to_b(env, counters[P] - counters[RA], fun);
	rreverse(env, counters[RA], counters[RB], fun);
	sort_a_to_b(env, counters[RA], fun);
	sort_b_to_a(env, counters[RB], fun);
}

void	sort_a_to_b(t_env *env, int cnt, int (*fun)(t_env *, int))
{
	int	counters[3];
	int	pivots[2];

	ft_memset(counters, 0, sizeof(int) * 3);
	if (cnt <= 2)
		return (sort_two(env, env->a, ACT_ID__A, fun));
	if (check_order_until_i(env->a, cnt) == ORDERED)
		return ;
	find_pivot(env, env->a, pivots, cnt);
	while (cnt && check_if_all_bigger_until_i(env->a, pivots[1], cnt) == MISC)
	{
		if (get_value(env->a.head->content) >= pivots[1])
			counters[RA] += fun(env, ACT_ID_R_ + ACT_ID__A);
		else
		{
			counters[P] += fun(env, ACT_ID_P_ + ACT_ID__B);
			if (get_value(env->b.head->content) >= pivots[0])
				counters[RB] += fun(env, ACT_ID_R_ + ACT_ID__B);
		}
		cnt--;
	}
	rreverse(env, counters[RA], counters[RB], fun);
	counters[RA] += cnt;
	sort_a_to_b(env, counters[RA], fun);
	sort_b_to_a(env, counters[RB], fun);
	sort_b_to_a(env, counters[P] - counters[RB], fun);
}

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
