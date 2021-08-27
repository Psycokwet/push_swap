/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/14 23:21:53 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_both(t_env *env)
{
	print_stack(env->a);
	print_stack(env->b);
	return (ACTION_DONE);
}
