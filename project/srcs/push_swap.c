/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 15:09:21 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rreverse(t_env *env, int ra_cnt, int rb_cnt, int (*fun)(t_env *, int))
{
	// printf("RA %d: RB %d:\n", ra_cnt, rb_cnt);
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

void	sort_lowcase(t_env *env, int cnt, int flag, int (*fun)(t_env *, int))
{
	// printf("sort_lowcase %d:%d\n",  cnt, flag);
	if (flag == 1 && cnt == 2)
	{
		if (get_value(env->a.head->content) > get_value(env->a.head->next->content))
			fun(env, ACT_ID_S_ + ACT_ID__A);
	}
	if (flag == 0)
	{
		if (cnt == 1)
			fun(env, ACT_ID_P_ + ACT_ID__A);
		else if (cnt == 2)
		{
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
	}
}

void	sort_b_to_a(t_env *env, int cnt, int (*fun)(t_env *, int))
{
	// printf("sort_b_to_a\n");
	int ra_cnt = 0;
	int rb_cnt = 0;
	int p_cnt = 0;
	int pivots[2];

	if (cnt <= 2)
		return (sort_lowcase(env, cnt, 0, fun));
	find_pivot(env, env->b, pivots, cnt);
	// printf("PIVOTS %d:%d:%d\n", pivots[0], pivots[1], cnt);
	while (cnt--)
	{

	// printf("PIVOTS %d:%d:%d\n", pivots[0], pivots[1], cnt);
		if (get_value(env->b.head->content) < pivots[0])
		{
			rb_cnt += fun(env, ACT_ID_R_ + ACT_ID__B);
		}
		else
		{
			p_cnt += fun(env, ACT_ID_P_ + ACT_ID__A);
			if (get_value(env->a.head->content) < pivots[1])
				ra_cnt += fun(env, ACT_ID_R_ + ACT_ID__A);
		}
	}
	// printf("p %d:ra %d:rb %d: cnt %d\n", p_cnt, ra_cnt, rb_cnt, cnt);
	sort_a_to_b(env, p_cnt - ra_cnt, fun);
	rreverse(env, ra_cnt, rb_cnt, fun);
	sort_a_to_b(env, ra_cnt, fun);
	sort_b_to_a(env, rb_cnt, fun);
	// sort_a_to_b(env, p_cnt - ra_cnt, fun);
	// rreverse(env, ra_cnt, rb_cnt, fun);
	// sort_a_to_b(env, ra_cnt, fun);
	// sort_b_to_a(env, env->b.total_item, fun);
	// printf("END sort_b_to_a\n");
}

void	sort_a_to_b(t_env *env, int cnt, int (*fun)(t_env *, int))
{
	// printf("sort_a_to_b\n");
	int ra_cnt = 0;
	int rb_cnt = 0;
	int p_cnt = 0;
	int pivots[2];

	if (cnt <= 2)
		return (sort_lowcase(env, cnt, 1, fun));
	if (check_order_until_i(env->a, cnt) == ORDERED)
		return ;
	find_pivot(env, env->a, pivots, cnt);
	// printf("PIVOTS %d:%d:%d:%d\n", pivots[0], pivots[1], cnt, check_if_all_bigger(env->a, pivots[1]));
	// int print = false;
	// 		if( pivots[0] == 403 && pivots[1] == 406 && cnt == 4)
	// 			print = true;
	while (cnt && check_if_all_bigger_until_i(env->a, pivots[1], cnt) == MISC)
	{

		// if( print == true){
			// printf("PIVOTS %d:%d:%d:%d\n", pivots[0], pivots[1], cnt, check_if_all_bigger(env->a, pivots[1]));

		// 	printf("%d\n\n",get_value(env->a.head->content));}
		if (get_value(env->a.head->content) >= pivots[1]){
			// if( print == true)
			// 	print_both(env);
			ra_cnt += fun(env, ACT_ID_R_ + ACT_ID__A);
		}
		else
		{
			p_cnt += fun(env, ACT_ID_P_ + ACT_ID__B);
			if (get_value(env->b.head->content) >= pivots[0])
				rb_cnt += fun(env, ACT_ID_R_ + ACT_ID__B);
		}
		cnt--;
	}
	// printf("p %d:ra %d:rb %d: cnt %d\n", p_cnt, ra_cnt, rb_cnt, cnt);

	rreverse(env, ra_cnt, rb_cnt, fun);
	ra_cnt += cnt;
	sort_a_to_b(env, ra_cnt, fun);
	sort_b_to_a(env, rb_cnt, fun);
	sort_b_to_a(env, p_cnt - rb_cnt, fun);
	// rreverse(env, ra_cnt, rb_cnt, fun);
	// ra_cnt += cnt;
	// sort_a_to_b(env, ra_cnt, fun);
	// sort_b_to_a(env, env->b.total_item, fun);
	// sort_b_to_a(env, p_cnt - rb_cnt, fun);
	// printf("END sort_a_to_b\n");
}

void	push_swap(t_env *env)
{
	if (env->total_item < 2)
		return;
	else if (env->total_item == 2)
	{
		sort_two(env, env->a, ACT_ID__A, &start_action_ps);
		return ;
	}
	else if (env->total_item == 3)
	{
		sort_three(env, env->a, ACT_ID__A, &start_action_ps);
		return ;
	}
	else if (env->total_item == 4)
	{
		start_brute_force(env);
		return ;
	}
	else if (env->total_item == 5)
	{
		sort_five(env, &start_action_ps);
		print_both(env);
		return ;
	}
	init_position_array(env);
	sort_a_to_b(env, env->total_item, &start_action_for_optimization);
	optimise_action_stack(env);
	reset_a_and_b(env);
	execute_action_stack(env, &start_action_ps);
}
