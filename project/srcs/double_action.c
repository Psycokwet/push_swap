/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 11:00:03 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	double_action(t_env *env, int (*fun_a)(t_env*), int (*fun_b)(t_env*))
{
	int	a_ret;
	int	b_ret;

	a_ret = fun_a(env);
	b_ret = fun_b(env);
	if (a_ret == ACTION_DONE && b_ret == ACTION_DONE)
		return (ACTION_DONE);
	if (a_ret == ACTION_DONE || b_ret == ACTION_DONE)
		return (INCOMPLETE_ACTION);
	return (NO_ACTION_DONE);
}
