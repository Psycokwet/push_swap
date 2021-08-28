/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/27 16:24:38 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_stack_int(void *content)
{
	ft_putstr_fd("        ", 1);
	ft_putnbr_fd(*(int *)content, 1);
	ft_putstr_fd("\n", 1);
}

void	print_stack(t_stack stack)
{
	ft_putstr_fd("        Start stack, size : ", 1);
	ft_putnbr_fd(stack.total_item, 1);
	ft_putstr_fd(", bigger elem ", 1);
	ft_putnbr_fd(stack.bigger_elem, 1);
	ft_putstr_fd("\n", 1);
	if (stack.head)
		ft_lstdbiter_fun_first(stack.head, &print_stack_int);
	ft_putstr_fd("        End stack\n", 1);
}
