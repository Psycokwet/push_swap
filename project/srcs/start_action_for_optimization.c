/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_action_for_optimization.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/30 20:37:33 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	start_action_for_optimization(t_env *env, int index)
{
	int	result;

	result = start_action_ps_silent(env, index);
	add_back_action_stack(env, index);
	return (result);
}
