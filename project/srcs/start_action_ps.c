/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_action_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/14 13:52:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	start_action_ps(t_env *env, int index)
{
	if (index >= MAX_ACTION_TYPE)
		error(env, ERROR_INST_DONT_EXIST_OR_INCORRECT);
	ft_putstr_fd(g_actions_types[index].code.str, 1);
	ft_putstr_fd("\n", 1);
	g_actions_types[index].action(env);
}
