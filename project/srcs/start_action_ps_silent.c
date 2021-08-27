/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_action_ps_silent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/22 17:01:55 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	start_action_ps_silent(t_env *env, int index)
{
	if (index >= MAX_ACTION_TYPE)
		error(env, ERROR_INST_DONT_EXIST_OR_INCORRECT);
	return (g_actions_types[index].action(env));
}
