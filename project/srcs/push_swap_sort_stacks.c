/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/10/17 17:56:20 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define RA	0
#define RB	1
#define P	2

void	roll_back_to_order(t_env *env, int *counters, int (*fun)(t_env *, int))
{
	int	i;

	i = 0;
	while (i < counters[RA] && i < counters[RB])
	{
		fun(env, ACT_ID_RRR);
		++i;
	}
	while (i < counters[RA])
	{
		fun(env, ACT_ID_RR_ + ACT_ID__A);
		++i;
	}
	while (i < counters[RB])
	{
		fun(env, ACT_ID_RR_ + ACT_ID__B);
		++i;
	}
}

void	sort_b_up_to_2(t_env *env, int counter, int (*fun)(t_env *, int))
{
	if (counter == 1)
	{
		fun(env, ACT_ID_P_ + ACT_ID__A);
		return ;
	}
	else if (counter != 2)
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

void	sort_b_to_a(t_env *env, int counter, int (*fun)(t_env *, int))
{
	int	counters[3];
	int	pivots[2];

	ft_memset(counters, 0, sizeof(int) * 3);
	if (counter <= 2)
		return (sort_b_up_to_2(env, counter, fun));
	find_pivots(env, env->b, pivots, counter);
	while (counter--)
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
	roll_back_to_order(env, counters, fun);
	sort_a_to_b(env, counters[RA], fun);
	sort_b_to_a(env, counters[RB], fun);
}

void	sort_a_to_b_int(t_env *env, int counter, int counters[3],
int (*fun)(t_env *, int))
{
	roll_back_to_order(env, counters, fun);
	counters[RA] += counter;
	sort_a_to_b(env, counters[RA], fun);
	sort_b_to_a(env, counters[RB], fun);
	sort_b_to_a(env, counters[P] - counters[RB], fun);
}

void	sort_a_to_b(t_env *env, int counter, int (*fun)(t_env *, int))
{
	int	counters[3];
	int	pivots[2];

	ft_memset(counters, 0, sizeof(int) * 3);
	if (counter <= 2)
		return (sort_two(env, env->a, ACT_ID__A, fun));
	if (check_order_until_i(env->a, counter) == ORDERED)
		return ;
	find_pivots(env, env->a, pivots, counter);
	while (counter && check_if_all_bigger_until_i(env->a, pivots[1],
			counter) == MISC)
	{
		if (get_value(env->a.head->content) >= pivots[1])
			counters[RA] += fun(env, ACT_ID_R_ + ACT_ID__A);
		else
		{
			counters[P] += fun(env, ACT_ID_P_ + ACT_ID__B);
			if (get_value(env->b.head->content) >= pivots[0])
				counters[RB] += fun(env, ACT_ID_R_ + ACT_ID__B);
		}
		counter--;
	}
	sort_a_to_b_int(env, counter, counters, fun);
}
