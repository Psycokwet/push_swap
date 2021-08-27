/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/22 20:08:00 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	sort_AtoB(t_env *env, int cnt, int (*fun)(t_env *, int));
// void	sort_BtoA(t_env *env, int cnt, int (*fun)(t_env *, int));
// void	rreverse(t_env *env, int ra_cnt, int rb_cnt, int (*fun)(t_env *, int))
// {
// 	int	i;

// 	i = 0;
// 	while (i < ra_cnt && i < rb_cnt)
// 	{
// 		fun(env, ACT_ID_RRR);
// 		++i;
// 	}
// 	while (i < ra_cnt)
// 	{
// 		fun(env, ACT_ID_RR_ + ACT_ID__A);
// 		++i;
// 	}
// 	while (i < rb_cnt)
// 	{
// 		fun(env, ACT_ID_RR_ + ACT_ID__B);
// 		++i;
// 	}
// }

// void	sort_lowcase(t_env *env, int cnt, int flag, int (*fun)(t_env *, int))
// {
// 	if (flag == 1 && cnt == 2)
// 	{
// 		if (*(int*)env->a.head->content > *(int*)env->a.head->next->content)
// 			fun(env, ACT_ID_S_ + ACT_ID__A);
// 	}
// 	if (flag == 0)
// 	{
// 		if (cnt == 1)
// 			fun(env, ACT_ID_P_ + ACT_ID__A);
// 		else if (cnt == 2)
// 		{
// 			if (*(int*)env->b.head->content > *(int*)env->b.head->next->content)
// 			{
// 				fun(env, ACT_ID_P_ + ACT_ID__A);
// 				fun(env, ACT_ID_P_ + ACT_ID__A);
// 			}
// 			else
// 			{
// 				fun(env, ACT_ID_S_ + ACT_ID__B);
// 				fun(env, ACT_ID_P_ + ACT_ID__A);
// 				fun(env, ACT_ID_P_ + ACT_ID__A);
// 			}
// 		}
// 	}
// }

// void	sort_BtoA(t_env *env, int cnt, int (*fun)(t_env *, int))
// {
// 	int ra_cnt = 0;
// 	int rb_cnt = 0;
// 	int pa_cnt = 0;

// 	if (cnt <= 2)
// 		return (sort_lowcase(env, cnt, 0, fun));
// 	find_pivot(env, env->b);
// 	while (cnt--)
// 	{
// 		if (*(int*)env->b.head->content < env->pivot1)
// 			rb_cnt += fun(env, ACT_ID_R_ + ACT_ID__B);
// 		else
// 		{
// 			pa_cnt += fun(env, ACT_ID_P_ + ACT_ID__A);
// 			if (*(int*)env->a.head->content < env->pivot2)
// 				ra_cnt += fun(env, ACT_ID_R_ + ACT_ID__A);
// 		}
// 	}
// 	sort_AtoB(env, pa_cnt - ra_cnt, fun);
// 	rreverse(env, ra_cnt, rb_cnt, fun);
// 	sort_AtoB(env, ra_cnt, fun);
// 	sort_BtoA(env, rb_cnt, fun);
// }

// void	sort_AtoB(t_env *env, int cnt, int (*fun)(t_env *, int))
// {
// 	int ra_cnt = 0;
// 	int rb_cnt = 0;
// 	int pb_cnt = 0;

// 	if (cnt <= 2)
// 		return (sort_lowcase(env, cnt, 1, fun));
// 	if (check_order(env->a) == ORDERED)
// 		return ;
// 	find_pivot(env, env->a);
// 	while (cnt && !check_if_all_bigger(env->a, env->pivot2))
// 	{
// 		if (*(int*)env->a.head->content >= env->pivot2)
// 			ra_cnt += fun(env, ACT_ID_R_ + ACT_ID__A);
// 		else
// 		{
// 			pb_cnt += pb(env);
// 			if (*(int*)env->b.head->content >= env->pivot1)
// 				rb_cnt += fun(env, ACT_ID_R_ + ACT_ID__B);
// 		}
// 		cnt--;
// 	}
// 	rreverse(env, ra_cnt, rb_cnt, fun);
// 	ra_cnt += cnt;
// 	sort_AtoB(env, ra_cnt, fun);
// 	sort_BtoA(env, rb_cnt, fun);
// 	sort_BtoA(env, pb_cnt - rb_cnt, fun);
// }





void	sort_three(t_env *env, t_stack stack, int base_id, int (*fun)(t_env *, int))
{
	int	nb[3] = { *(int*)stack.head->content, *(int*)stack.head->next->content, *(int*)stack.head->next->next->content};

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

// // void	sort_three(t_env *env, t_stack stack, int base_id, int (*fun)(t_env *, int))
// // {
// // 	int	nb[3] = { *(int*)stack.head->content, *(int*)stack.head->next->content, *(int*)stack.head->next->next->content};

// // 	if (nb[0] < nb[1] && nb[1] < nb[2])
// // 		return ;
// // 	if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] < nb[2]) // 2>1<3
// // 		fun(env, ACT_ID_S_ + base_id);
// // 	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] < nb[2]) 
// // 	{
// // 		fun(env, ACT_ID_RR_ + base_id);
// // 		fun(env, ACT_ID_S_ + base_id);
// // 	}
// // 	else if (nb[0] > nb[1] && nb[0] > nb[2] && nb[1] < nb[2]) 
// // 		fun(env, ACT_ID_R_ + base_id);
// // 	else if (nb[0] < nb[1] && nb[0] > nb[2] && nb[1] > nb[2])
// // 		fun(env, ACT_ID_RR_ + base_id);
// // 	else if (nb[0] > nb[1] && nb[1] > nb[2])
// // 	{
// // 		fun(env, ACT_ID_R_ + base_id);
// // 		fun(env, ACT_ID_S_ + base_id);
// // 	}
// // }

// // void	sort_four(t_env *env)
// // {

// // }
// // void	sort_five(t_env *env, void (*fun)(t_env*, int))
// // {
// // 	// fun(env, ACT_ID_P_ + ACT_ID__B);
// // 	// fun(env, ACT_ID_P_ + ACT_ID__B);
// // 	// sort_three(env, env->a, ACT_ID__A, fun);
// // 	// // sort_two(env, env->b, ACT_ID__B); incomplete
// // 	// fun(env, ACT_ID_P_ + ACT_ID__A);
// // 	// fun(env, ACT_ID_P_ + ACT_ID__A);
// // }


// // typedef struct s_current_state
// // {
// // 	int		max_move;
// // 	int		index_mid;
// // 	int		value_mid;
// // 	int		index_curr;
// // 	int		src;
// // 	int		dst;
// // 	t_stack	*stack;
// // 	t_list	*current_node;
// // 	void	(*fun)(t_env*, int);
// // }	t_current_state;

// // t_current_state build_next_state(t_current_state current, int index_curr, t_list *next_node)
// // {
// // 	current.index_curr = index_curr;
// // 	current.current_node = next_node;
// // 	return (current);
// // }
// // void	ft_lstiter_use_pivot(t_env *env, t_current_state cs)
// // {
// // 	t_list *next_node;
// // 	if (!cs.current_node || cs.max_move == cs.index_curr || cs.stack->total_item <= 3)
// // 		return ;
// // 	next_node = cs.current_node->next;
// // 	printf("WTD : %d: %d\n", *(int*)cs.current_node->content, cs.value_mid);
// // 	if (*(int*)cs.current_node->content < cs.value_mid)
// // 	{
// // 		cs.fun(env, ACT_ID_P_ + cs.dst);
// // 		if (cs.current_node->next && *(int*)cs.current_node->content < *(int*)cs.current_node->next->content)
// // 		{
// // 			cs.fun(env, ACT_ID_S_ + cs.dst);
// // 		}
// // 	}
// // 	else
// // 		cs.fun(env, ACT_ID_R_ + cs.src);
// // 	ft_lstiter_use_pivot(env, build_next_state(cs, cs.index_curr + 1, next_node));
// // }


// // t_current_state build_start_a_to_b(t_env *env, int index_mid, int value_mid, void (*fun)(t_env *, int))
// // {
// // 	return ((t_current_state){env->a.total_item, index_mid, value_mid, 0, ACT_ID__A, ACT_ID__B, &env->a, env->a.head, fun});
// // }


// // t_current_state build_start_b_to_a(t_env *env, int index_mid, int value_mid, void (*fun)(t_env *, int))
// // {
// // 	return ((t_current_state){env->b.total_item, index_mid, value_mid, 0, ACT_ID__B, ACT_ID__A, &env->b, env->b.head, fun});
// // }





// // void	mid_elem_sort(t_env *env, t_stack stack, void (*fun)(t_env *, int), t_current_state (*build_start_state)(t_env *, int, int, void (*)(t_env *, int)))
// // {
// // 	int index_mid = stack.total_item / 2;
// // 	find_pivot(env, stack);
// // 	t_list* mid_elem = ft_lst_get_elem_by_nb(stack.head, index_mid);
// // 	print_both(env);
// // 	printf("MID ELEME IS : %d:%d:%d\n", *(int*)mid_elem->content, index_mid, stack.total_item);
// // 	ft_lstiter_use_pivot(env, build_start_state(env, index_mid, *(int*)mid_elem->content, fun));
// // 	print_both(env);
// // }


// // void	sort_100(t_env *env, void (*fun)(t_env *, int))
// // {
// // 	while(env->a.total_item > 3)
// // 		mid_elem_sort(env, env->a, fun, &build_start_a_to_b);
// // 	sort_three(env, env->a, ACT_ID__A, fun);
// // 	printf("reciproque\n");
// // 	// while(env->b.total_item > 3)
// // 		mid_elem_sort(env, env->b, fun, &build_start_b_to_a);
// // }

void	sort_two(t_env *env, t_stack stack, int base_id, int (*fun)(t_env *, int))
{
	if (stack.total_item >= 2 && *(int *)stack.head->content > *(int *)stack.head->next->content)
		fun(env, ACT_ID_S_ + base_id);
}

// // void	sort_two_reverse(t_env *env, t_stack stack, int base_id, void (*fun)(t_env *, int))
// // {
// // 	if (stack.total_item >= 2 && *(int *)stack.head->content < *(int *)stack.head->next->content)
// // 		fun(env, ACT_ID_S_ + base_id);
// // }



// int	find_required_position(t_stack stack)
// {
// 	int		pos;
// 	t_list	*tmp;

// 	pos = 0;
// 	tmp = stack.head;
// 	while (tmp)
// 	{
// 		if ( *(int*)stack.head->content > *(int*)tmp->content)
// 			++pos;
// 		tmp = tmp->next;
// 	}
// 	return (pos);
// }


// void	switch_position(t_env* env, t_stack stack, int id_stack, int (*fun)(t_env*, int))
// {
// 	int	pos;

// 	pos = find_required_position(stack);
// 	printf("pos %d\n", pos);
// 	if (!pos)
// 		return ;
// 	else if (pos == 1)
// 		fun(env,  ACT_ID_S_ + id_stack);
// 		// sa(g);
// 	else if (pos == 2)
// 	{
// 	print_both(env);
// 		fun(env,  ACT_ID_S_ + id_stack);
// 		fun(env,  ACT_ID_R_ + id_stack);
// 		fun(env,  ACT_ID_S_ + id_stack);
// 		fun(env,  ACT_ID_RR_ + id_stack);
// 		// sa(g);
// 		// ra(g);
// 		// sa(g);
// 		// rra(g);
// 	}
// 	else if (pos == 3 && stack.total_item == 4)
// 		fun(env,  ACT_ID_R_ + id_stack);
// 		// ra(g);
// 	else if (pos == 3 && stack.total_item == 5)
// 	{
// 		fun(env,  ACT_ID_RR_ + id_stack);
// 		fun(env,  ACT_ID_S_ + id_stack);
// 		fun(env,  ACT_ID_R_ + id_stack);
// 		fun(env,  ACT_ID_R_ + id_stack);
// 		// rra(g);
// 		// sa(g);
// 		// ra(g);
// 		// ra(g);
// 	}
// 	else
// 		fun(env,  ACT_ID_R_ + id_stack);
// 		// ra(g);
// }

// void	sort_five(t_env *env, int (*fun)(t_env *, int))
// {
// 	fun(env, ACT_ID_P_ + ACT_ID__B);
// 	fun(env, ACT_ID_P_ + ACT_ID__B);
// 	sort_three(env, env->a, ACT_ID__A, fun);
// 	fun(env,  ACT_ID_P_ + ACT_ID__A);
// 	switch_position(env, env->a, ACT_ID__A, fun);
// 	fun(env, ACT_ID_P_ + ACT_ID__A);
// 	// switch_position(g_A);
// 	switch_position(env, env->a, ACT_ID__A, fun);
// }

void	*copy_content(void* src, void* dst)
{
	*(int*)dst = *(int*)src;
	return (dst);
}



void	reset_a_and_b(t_env *env)
{
	while(env->b.total_item > 0)
		pa(env);
	ft_lstreset(env->c_a.head, env->a.head, &copy_content);
}

void	start_brute_force(t_env *env)
{
	int i = 0;
	while(env->action_stack.total_item < 15){
		// print_action_stack(env);
		upgrade_to_next_possibility(env);
		execute_action_stack(env, &start_action_ps_silent);

		if (env->b.head == NULL && check_order(env->a) == ORDERED)
		{
			// printf("IS ORDERED %d\n", check_order(env->a));
			// print_both(env);
			// print_action_stack(env);
			reset_a_and_b(env);
			execute_action_stack(env, &start_action_ps);
			return;
		}
		reset_a_and_b(env);
		i++;
	}
	// printf("EXIT AFTER %d\n",i);
	// print_action_stack(env);
	// upgrade_to_next_possibility(env);
	// print_action_stack(env);
	// upgrade_to_next_possibility(env);
	// print_action_stack(env);
	// upgrade_to_next_possibility(env);
	// print_action_stack(env);
	// upgrade_to_next_possibility(env);
	// print_action_stack(env);
}

void	print_position_array(t_env *env)
{
	int i;

	i = 0;
	while(i < env->total_item)
	{
		printf("[%d]:%d ", i, env->position_array[i]);
		i++;
	}
	printf("\n");
}

int		find_index_of(t_env* env, int value)
{
	int i;

	i = 0;
	while (i < env->total_item)
	{
		if (value == env->position_array[i])
			return (i);
		i++;
	}
	return (-EXIT_FAILURE);
}

void	algo(t_env *env)
{
	env->position_array = (int *)malloc(sizeof(int) * env->total_item);

	t_list	*item;
	int		i;

	i = 0;
	item = env->a.head;
	while(item){
		env->position_array[i] = *(int*)item->content;
		item = item->next;
		i++;
	}
	print_position_array(env);
	tri_bulle(env->position_array, env->total_item);
	print_position_array(env);
	printf("FIND INDEX OF %d : %d \n", 5, find_index_of(env, 5));
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
	algo(env);
	// else if (env->total_item == 5)
	// {
	// 	sort_five(env, &start_action_ps);
	// 	// print_both(env);
	// }
	// else //if (env->total_item == 4)
	// 	sort_AtoB(env, env->total_item, &start_action_ps);
	// 	// print_both(env);
	// // 	sort_four(env);
	// // else if (env->total_item == 5)
	// // 	sort_five(env, &start_action_ps);
	// // else
	// // 	sort_100(env, &start_action_ps);	
}
