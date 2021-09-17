/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 10:58:52 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*copy_content(void *src, void *dst)
{
	set_value(dst, get_value(src));
	return (dst);
}

void	reset_a_and_b(t_env *env)
{
	while (env->b.total_item > 0)
		pa(env);
	ft_lstdbreset(env->c_a.head, env->a.head, &copy_content);
}
