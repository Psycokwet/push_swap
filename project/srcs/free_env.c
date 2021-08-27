/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/27 11:18:29 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_env(t_env *env)
{
	ft_lstdbclear(&env->c_a.head, &free);
	env->c_a.head = NULL;
	ft_lstdbclear(&env->c_b.head, &free);
	env->c_b.head = NULL;
	ft_lstdbclear(&env->a.head, &free);
	env->a.head = NULL;
	ft_lstdbclear(&env->b.head, &free);
	env->b.head = NULL;
	clear_action_stack(env);
	env->action_stack.head = NULL;
	if(env->position_array)
		free(env->position_array);
	env->position_array = NULL;
}
