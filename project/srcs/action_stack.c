/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/14 13:56:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fake_free(void* content)
{
	(void)content;
}

void	clear_action_stack(t_env *env)
{
	ft_lstclear(&env->action_stack.head, &fake_free);
}

void	add_back_action_stack(t_env *env, int full_id)
{
	ft_lstadd_back(&env->action_stack.head, ft_lstnew((void*)&(g_actions_types[full_id])));
}

void	optimise_action_stack(t_env *env)
{
	(void)env;
}

void	execute_action_stack(t_env *env)
{
	(void)env;
}
