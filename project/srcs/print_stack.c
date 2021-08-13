/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 11:39:27 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack_int(void *content)
{
	ft_putnbr_fd(*(int *)content, 1);
	ft_putstr_fd("\n", 1);
}

void	print_stack(t_stack stack)
{
	ft_putstr_fd("Start stack\n", 1);
	if (stack.head)
		ft_lstiter_fun_first(stack.head, &print_stack_int);
	ft_putstr_fd("End stack\n", 1);
}
