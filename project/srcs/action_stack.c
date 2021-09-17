/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 15:01:54 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_action_stack(t_env *env)
{
	ft_lstdbclear(&env->action_stack.head, &free);
}

void	add_back_action_stack(t_env *env, int full_id)
{
	int	*content;

	content = (int *)malloc(sizeof(int));
	if (!content)
		error(env, ERROR_MALLOC);
	*content = full_id;
	ft_lstdbadd_back(&env->action_stack.head, ft_lstdbnew(content));
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

void	print_action_stack(t_env *env)
{
	ft_putstr_fd("        Action stack, size : ", 1);
	ft_putnbr_fd(env->action_stack.total_item, 1);
	ft_putstr_fd("\n", 1);
	if (env->action_stack.head)
		ft_lstdbiter_fun_first(env->action_stack.head,
			&print_action_stack_int);
	ft_putstr_fd("        End Action stack\n", 1);
	ft_putnbr_fd(env->action_stack.total_item, 1);
	ft_putstr_fd("\n", 1);
}
