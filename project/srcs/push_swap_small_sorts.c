/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sorts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 14:59:05 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define TARGET 0
#define NOT_TARGET -1
#define ERROR -2

int	is_target(void *target_util, void *current)
{
	if (get_value(target_util) > get_value(current))
		return (TARGET);
	return (NOT_TARGET);
}

void	switch_position(t_env *env, t_stack stack, int id_stack,
int (*fun)(t_env*, int))
{
	int	pos;

	pos = ft_lstdbcount(stack.head, stack.head->content, &is_target);
	if (pos <= 0)
		return ;
	if (stack.total_item < 2)
		return ;
	else if (pos == 1)
		fun(env, ACT_ID_S_ + id_stack);
	else if (pos == 2)
	{
		fun(env, ACT_ID_S_ + id_stack);
		fun(env, ACT_ID_R_ + id_stack);
		fun(env, ACT_ID_S_ + id_stack);
		fun(env, ACT_ID_RR_ + id_stack);
	}
	else if (pos == 3 && stack.total_item == 5)
	{
		fun(env, ACT_ID_RR_ + id_stack);
		fun(env, ACT_ID_S_ + id_stack);
		fun(env, ACT_ID_R_ + id_stack);
		fun(env, ACT_ID_R_ + id_stack);
	}
	else
		fun(env, ACT_ID_R_ + id_stack);
}

void	sort_five(t_env *env, int (*fun)(t_env *, int))
{
	init_position_array(env);
	print_position_array(env);
	fun(env, ACT_ID_P_ + ACT_ID__B);
	fun(env, ACT_ID_P_ + ACT_ID__B);
	sort_three(env, env->a, ACT_ID__A, fun);
	fun(env, ACT_ID_P_ + ACT_ID__A);
	switch_position(env, env->a, ACT_ID__A, fun);
	fun(env, ACT_ID_P_ + ACT_ID__A);
	switch_position(env, env->a, ACT_ID__A, fun);
}

void	sort_three(t_env *env, t_stack stack, int base_id,
int (*fun)(t_env *, int))
{
	int	nb[3];

	nb[0] = get_value(stack.head->content);
	nb[1] = get_value(stack.head->next->content);
	nb[2] = get_value(stack.head->next->next->content);
	if (nb[0] < nb[1] && nb[1] < nb[2])
		return ;
	if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] < nb[2]) // 2>1<3
		fun(env, ACT_ID_S_ + base_id);
	else if (nb[0] > nb[1] && nb[1] > nb[2] && nb[0] > nb[2]) //3>2>1
	{
		fun(env, ACT_ID_S_ + base_id);
		fun(env, ACT_ID_RR_ + base_id);
	}
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] > nb[2]) //3>1<2
		fun(env, ACT_ID_R_ + base_id);
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] < nb[2]) // 1<3>2
	{
		fun(env, ACT_ID_S_ + base_id);
		fun(env, ACT_ID_R_ + base_id);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] > nb[2]) //2<3>1
		fun(env, ACT_ID_RR_ + base_id);
}

void	sort_two(t_env *env, t_stack stack, int base_id,
int (*fun)(t_env *, int))
{
	if (stack.total_item >= 2 && get_value(stack.head->content)
		> get_value(stack.head->next->content))
		fun(env, ACT_ID_S_ + base_id);
}
