/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_both_from_tail.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/27 12:25:14 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_both_from_tail(t_env *env)
{
	print_stack_from_tail(env->a);
	print_stack_from_tail(env->b);
	return (ACTION_DONE);
}
