/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_action_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/30 17:47:31 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	start_action_ps(t_env *env, int index)
{
	if (index >= MAX_ACTION_TYPE)
		error(env, ERROR_INST_DONT_EXIST_OR_INCORRECT);
	ft_putstr_fd(g_actions_types[index].code.str, 1);
	ft_putstr_fd("\n", 1);
	int tmp = g_actions_types[index].action(env);
	// ft_putstr_fd("RESULT ACTION ", 1);
	// ft_putstr_fd(g_actions_types[index].code.str, 1);
	// ft_putnbr_fd(tmp, 1);
	// ft_putstr_fd("\n", 1);
	// print_both(env);
	return (1);
}
