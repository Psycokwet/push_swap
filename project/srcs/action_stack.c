/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/22 17:24:55 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fake_free(void* content)
{
	(void)content;
}

// void	clear_action_stack(t_env *env)
// {
// 	ft_lstclear(&env->action_stack.head, &fake_free);
// }

void	clear_action_stack(t_env *env)
{
	ft_lstclear(&env->action_stack.head, &free);
}

// void	add_back_action_stack(t_env *env, int full_id)
// {
// 	ft_lstadd_back(&env->action_stack.head, ft_lstnew((void*)&(g_actions_types[full_id])));
// 	env->action_stack.total_item++;
// }

void	add_back_action_stack(t_env *env, int full_id)
{
	int *content = (int *)malloc(sizeof(int));
	if(!content)
		error(env, ERROR_MALLOC);
	*content = full_id;
	ft_lstadd_back(&env->action_stack.head, ft_lstnew(content));
	env->action_stack.total_item++;
}

void	print_action_stack_int(void *content)
{
	ft_putstr_fd("        ", 1);
	ft_putnbr_fd(*(int *)content, 1);
	ft_putstr_fd(" : ", 1);
	ft_putstr_fd(g_actions_types[*(int *)content].code.str, 1);
	ft_putstr_fd("\n", 1);
}

void	print_action_stack(t_env* env)
{

	ft_putstr_fd("        Action stack, size : ", 1);
	ft_putnbr_fd(env->action_stack.total_item, 1);
	ft_putstr_fd("\n", 1);
	if (env->action_stack.head)
		ft_lstiter_fun_first(env->action_stack.head, &print_action_stack_int);
	ft_putstr_fd("        End Action stack\n", 1);

}

#define STARTED 0
#define MAXED_OUT_TILL_NOW 1
#define NOT_MAXED_OUT 2
#define ADD_NEW_ACTION 3
#define NEXT_IS_UPGRADED 4
#define STOP_UPGRADE 5
int	upgrade_to_next_possibility_int(t_env *env, t_list *action, int state)
{
	int ret;
	if (*(int*)action->content == ACT_ID_RRR && (state == STARTED || state == MAXED_OUT_TILL_NOW ))
		state = MAXED_OUT_TILL_NOW;
	else
		state = NOT_MAXED_OUT;

	if (!action->next)
	{
		if (*(int*)action->content == ACT_ID_RRR && state == MAXED_OUT_TILL_NOW)
		{
			add_back_action_stack(env, 0);
			*(int*)action->content = 0;
			return (ADD_NEW_ACTION);
		}
		else if (*(int*)action->content == ACT_ID_RRR)
		{
			*(int*)action->content = 0;
			return (NEXT_IS_UPGRADED);
		}
		else
		{
			(*(int*)action->content)++;
			return (STOP_UPGRADE);
		}
	}
	ret = upgrade_to_next_possibility_int(env, action->next, state);
	if (ret == ADD_NEW_ACTION)
	{
		*(int*)action->content = 0;
		return (ADD_NEW_ACTION);
	}
	else if(ret == NEXT_IS_UPGRADED && *(int*)action->content == ACT_ID_RRR)
	{
		*(int*)action->content = 0;
		return (NEXT_IS_UPGRADED);
	}
	else if(ret == NEXT_IS_UPGRADED && *(int*)action->content != ACT_ID_RRR)
	{
		(*(int*)action->content)++;
		return (STOP_UPGRADE);
	}
	return (STOP_UPGRADE);
}

void	upgrade_to_next_possibility(t_env *env)
{
	if(!env->action_stack.head)
		add_back_action_stack(env, 0);
	else
		upgrade_to_next_possibility_int(env, env->action_stack.head, STARTED);
}

void	optimise_action_stack(t_env *env)
{
	(void)env;
}

void	execute_action_stack_int(t_env *env, t_list *action, int (*fun)(t_env*, int))
{
	if (!action || !fun)
		return ;
	(*fun)(env, *(int*)action->content);
	execute_action_stack_int(env, action->next, fun);
}

void	execute_action_stack(t_env *env, int (*fun)(t_env*, int))
{
	execute_action_stack_int(env, env->action_stack.head, fun);
}
