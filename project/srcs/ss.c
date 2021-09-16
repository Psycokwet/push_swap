/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 11:09:49 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ss(t_env *env)
{
	int sa_ret;
	int sb_ret;

	sa_ret = sa(env);
	sb_ret = sb(env);
	if(sa_ret == ACTION_DONE && sb_ret == ACTION_DONE)
		return (ACTION_DONE);
	if(sa_ret == ACTION_DONE || sb_ret == ACTION_DONE)
		return (INCOMPLETE_ACTION);
	return (NO_ACTION_DONE);
}
