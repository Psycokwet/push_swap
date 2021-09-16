/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 11:10:24 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rr(t_env *env)
{
	int ra_ret;
	int rb_ret;

	ra_ret = ra(env);
	rb_ret = rb(env);
	if(ra_ret == ACTION_DONE && rb_ret == ACTION_DONE)
		return (ACTION_DONE);
	if(ra_ret == ACTION_DONE || rb_ret == ACTION_DONE)
		return (INCOMPLETE_ACTION);
	return (NO_ACTION_DONE);
}
