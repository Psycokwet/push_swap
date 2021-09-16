/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 11:10:07 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rrr(t_env *env)
{
	int rra_ret;
	int rrb_ret;

	rra_ret = rra(env);
	rrb_ret = rrb(env);
	if(rra_ret == ACTION_DONE && rrb_ret == ACTION_DONE)
		return (ACTION_DONE);
	if(rra_ret == ACTION_DONE || rrb_ret == ACTION_DONE)
		return (INCOMPLETE_ACTION);
	return (NO_ACTION_DONE);
}
