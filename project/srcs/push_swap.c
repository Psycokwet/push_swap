/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 11:03:40 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_env *env, t_stack stack, int base_id, int (*fun)(t_env *, int));

void	sort_two(t_env *env, t_stack stack, int base_id, int (*fun)(t_env *, int));


int	find_position(t_stack stack)
{
	int				pos;
	t_list_double	*tmp;

	pos = 0;
	tmp = stack.head;
	while (tmp)
	{
		if (get_value(stack.head->content) > get_value(tmp->content))
			++pos;
		tmp = tmp->next;
	}
	return (pos);
}


#define TARGET 0
#define NOT_TARGET -1
#define ERROR -2


int		is_target(void *target_util, void* current)
{
	if(get_value(target_util) > get_value(current))
		return (TARGET);
	return (NOT_TARGET);
}


void	switch_position(t_env* env, t_stack stack, int id_stack, int (*fun)(t_env*, int))
{
	int pos;

	pos = ft_lstdbcount(stack.head, stack.head->content, &is_target);
	if (pos <= 0)
		return ;
	if (stack.total_item < 2)
		return ;
	else if (pos == 1)
		fun(env,  ACT_ID_S_ + id_stack);
	else if (pos == 2)
	{
		fun(env,  ACT_ID_S_ + id_stack);
		fun(env,  ACT_ID_R_ + id_stack);
		fun(env,  ACT_ID_S_ + id_stack);
		fun(env,  ACT_ID_RR_ + id_stack);
	}
	else if (pos == 3 && stack.total_item == 4)
		fun(env,  ACT_ID_R_ + id_stack);
	else if (pos == 3 && stack.total_item == 5)
	{
		fun(env,  ACT_ID_RR_ + id_stack);
		fun(env,  ACT_ID_S_ + id_stack);
		fun(env,  ACT_ID_R_ + id_stack);
		fun(env,  ACT_ID_R_ + id_stack);
	}
	else
		fun(env,  ACT_ID_R_ + id_stack);
}

void	sort_five(t_env *env, int (*fun)(t_env *, int))
{
	init_position_array(env);
	print_position_array(env);
	fun(env, ACT_ID_P_ + ACT_ID__B);
	fun(env, ACT_ID_P_ + ACT_ID__B);
	sort_three(env, env->a, ACT_ID__A, fun);
	fun(env,  ACT_ID_P_ + ACT_ID__A);
	switch_position(env, env->a, ACT_ID__A, fun);
	fun(env, ACT_ID_P_ + ACT_ID__A);
	switch_position(env, env->a, ACT_ID__A, fun);
}

void	sort_three(t_env *env, t_stack stack, int base_id, int (*fun)(t_env *, int))
{
	int	nb[3] = { get_value(stack.head->content), get_value(stack.head->next->content), get_value(stack.head->next->next->content)};

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

void	sort_two(t_env *env, t_stack stack, int base_id, int (*fun)(t_env *, int))
{
	if (stack.total_item >= 2 && *(int *)stack.head->content > *(int *)stack.head->next->content)
		fun(env, ACT_ID_S_ + base_id);
}

void	*copy_content(void* src, void* dst)
{
	set_value(dst, get_value(src));
	return (dst);
}

void	reset_a_and_b(t_env *env)
{
	while(env->b.total_item > 0)
		pa(env);
	ft_lstdbreset(env->c_a.head, env->a.head, &copy_content);
}

void	start_brute_force(t_env *env)
{
	int i = 0;
	while(env->action_stack.total_item < 15){
		upgrade_to_next_possibility(env);
		execute_action_stack(env, &start_action_ps_silent);

		if (env->b.head == NULL && check_order(env->a) == ORDERED)
		{
			reset_a_and_b(env);
			execute_action_stack(env, &start_action_ps);
			return;
		}
		reset_a_and_b(env);
		i++;
	}
}

void	print_pivots(t_env* env)
{
	printf("PIVOTS\n A1 [%d]\n B1 [%d]\n", env->pa.p1, env->pb.p1);
}

void	rotate_while_sorted(t_env *env, t_stack *stack, int (*fun)(t_env*, int))
{
	if (stack->head)
	{
		while (get_position(stack->head->content) == 0 || (stack->total_item > 1 && get_position(get_absolute_prev(stack, stack->head)->content) == get_position(stack->head->content) - 1))
		{
			fun(env, ACT_ID_R_ + ACT_ID__A);
		}
	}
}

void	validate_sorted_elem(t_env *env, t_stack *stack, t_list_double *elem)
{
	t_list_double *prev;

	prev = get_absolute_prev(stack, elem);
	if (!prev)
		return ;
	if (get_is_sorted(prev->content) == true && get_position(prev->content) == get_position(elem->content) - 1)
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
				&& (get_position(env->a.tail->content) == get_position(env->b.head->content) - 1))
			|| (get_value(env->b.head->content) >= env->pb.p1
				&& (get_position(env->a.head->content) == get_position(env->b.head->content) + 1))))))
	{ 
		fun(env, ACT_ID_P_ + ACT_ID__A);
	}
}

void	b_to_a(t_env *env, int (*fun)(t_env*, int))
{
	// find_pivot(env, env->a, &env->pa);
	find_pivot(env, env->b, &env->pb, env->b.total_item);
	print_pivots(env);
	//at least 0 pos is placed now

	while (env->b.total_item > 0)
	{
		print_both(env);
		validate_sorted_stack(env);
		rotate_while_sorted(env, &env->a, fun);
		push_if_sorted(env, fun);
		//should replace by a choice rrb or rb depending on proximity?
		fun(env, ACT_ID_R_ + ACT_ID__B);
	}
	rotate_while_sorted(env, &env->a, fun);
	validate_sorted_stack(env);
	printf("STEP 2\n");

	print_both(env);

	find_pivot(env, env->a, &env->pa, pivot_size_from_sorted_side(env, env->a));
	print_pivots(env);

}

void	algo(t_env *env, int (*fun)(t_env*, int))
{
	init_position_array(env);
	int mid_value = env->position_array[env->total_item / 2];
	print_both(env);
	while (check_if_all_bigger(env->a, mid_value) == MISC)
	{
		if ((get_value(env->a.head->content)) <= mid_value)
		{
			fun(env, ACT_ID_P_ + ACT_ID__B);
			continue;
		}
		fun(env, ACT_ID_R_ + ACT_ID__A);
	}
	print_both(env);
	// print_both_from_tail(env);
	// printf("FIND INDEX OF %d : %d \n", 5, find_index_of(env, 5));
	printf("STEP 1\n");
	b_to_a(env, fun);
}



void	sort_AtoB(t_env *env, int cnt, int (*fun)(t_env *, int));
void	sort_BtoA(t_env *env, int cnt, int (*fun)(t_env *, int));
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

void	sort_BtoA(t_env *env, int cnt, int (*fun)(t_env *, int))
{
	// printf("sort_BtoA\n");
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
	sort_AtoB(env, p_cnt - ra_cnt, fun);
	rreverse(env, ra_cnt, rb_cnt, fun);
	sort_AtoB(env, ra_cnt, fun);
	sort_BtoA(env, rb_cnt, fun);
	// sort_AtoB(env, p_cnt - ra_cnt, fun);
	// rreverse(env, ra_cnt, rb_cnt, fun);
	// sort_AtoB(env, ra_cnt, fun);
	// sort_BtoA(env, env->b.total_item, fun);
	// printf("END sort_BtoA\n");
}

void	sort_AtoB(t_env *env, int cnt, int (*fun)(t_env *, int))
{
	// printf("sort_AtoB\n");
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
	sort_AtoB(env, ra_cnt, fun);
	sort_BtoA(env, rb_cnt, fun);
	sort_BtoA(env, p_cnt - rb_cnt, fun);
	// rreverse(env, ra_cnt, rb_cnt, fun);
	// ra_cnt += cnt;
	// sort_AtoB(env, ra_cnt, fun);
	// sort_BtoA(env, env->b.total_item, fun);
	// sort_BtoA(env, p_cnt - rb_cnt, fun);
	// printf("END sort_AtoB\n");
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
	sort_AtoB(env, env->total_item, &start_action_ps);
	while(env->b.total_item > 0){
		start_action_ps(env, ACT_ID_P_ + ACT_ID__A);
	}
	// // sort_AtoB(env, env->total_item, &start_action_for_optimization);
	// // printf(" \n\nRESULLLT \n\n");
	// int tmp_bef = env->action_stack.total_item;
	// // print_action_stack(env);
	// // optimise_action_stack(env);
	// reset_a_and_b(env);
	// execute_action_stack(env, &start_action_ps);
	// // printf("AFTER OPTI %d:%d",tmp_bef, env->action_stack.total_item);
	// // algo(env, &start_action_ps);
	
	// print_both(env);
	// if (env->b.head == NULL && check_order(env->a) == ORDERED)
	// 	printf("SUCCESS\n")	;
	// else
	// 	printf("FAILE\n")	;
}
