/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/14 13:58:04 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_env *env, t_stack stack, int base_id, void (*fun)(t_env *, int))
{
	int	nb[3] = { *(int*)stack.head->content, *(int*)stack.head->next->content, *(int*)stack.head->next->next->content};

	if (nb[0] < nb[1] && nb[1] < nb[2])
		return ;
	if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] < nb[2]) // 2>1<3
		fun(env, ACT_ID_S_ + base_id);
		// start_action_ps(env, ACT_ID_S_ + base_id);
	else if (nb[0] > nb[1] && nb[1] > nb[2] && nb[0] > nb[2]) //3>2>1
	{
		fun(env, ACT_ID_S_ + base_id);
		fun(env, ACT_ID_RR_ + base_id);
		// start_action_ps(env, ACT_ID_S_ + base_id);
		// start_action_ps(env, ACT_ID_RR_ + base_id);
	}
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] > nb[2]) //3>1<2
		fun(env, ACT_ID_R_ + base_id);
		// start_action_ps(env, ACT_ID_R_ + base_id);
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] < nb[2]) // 1<3>2
	{
		fun(env, ACT_ID_S_ + base_id);
		fun(env, ACT_ID_R_ + base_id);
		// start_action_ps(env, ACT_ID_S_ + base_id);
		// start_action_ps(env, ACT_ID_R_ + base_id);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] > nb[2]) //2<3>1
		fun(env, ACT_ID_RR_ + base_id);
		// start_action_ps(env, ACT_ID_RR_ + base_id);
}

void	sort_four(t_env *env)
{

}
void	sort_five(t_env *env, void (*fun)(t_env*, int))
{
	fun(env, ACT_ID_P_ + ACT_ID__B);
	fun(env, ACT_ID_P_ + ACT_ID__B);
	sort_three(env, env->a, ACT_ID__A, fun);
	// sort_two(env, env->b, ACT_ID__B); incomplete
	fun(env, ACT_ID_P_ + ACT_ID__A);
	fun(env, ACT_ID_P_ + ACT_ID__A);
}

void	sort_100(t_env *env)
{
}


void	sort_two(t_env *env, t_stack stack, int base_id, void (*fun)(t_env *, int))
{
	if (stack.total_item == 2 && *(int *)stack.head->content > *(int *)stack.head->next->content)
		fun(env, ACT_ID_S_ + base_id);
		// start_action_ps(env, ACT_ID_S_ + base_id);
}

void	sort_two_reverse(t_env *env, t_stack stack, int base_id, void (*fun)(t_env *, int))
{
	if (stack.total_item == 2 && *(int *)stack.head->content < *(int *)stack.head->next->content)
		fun(env, ACT_ID_S_ + base_id);
		// start_action_ps(env, ACT_ID_S_ + base_id);
}

void	push_swap(t_env *env)
{
	if (env->total_item < 2)
		return;
	else if (env->total_item == 2)
		sort_two(env, env->a, ACT_ID__A, &start_action_ps);
	else if (env->total_item == 3)
		sort_three(env, env->a, ACT_ID__A, &start_action_ps);
	else if (env->total_item == 4)
		sort_four(env);
	else if (env->total_item == 5)
		sort_five(env, &start_action_ps);
	else
		sort_100(env);	
}
