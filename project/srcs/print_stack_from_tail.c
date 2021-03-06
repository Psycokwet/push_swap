/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_from_tail.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 10:57:27 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_stack_int(void *content)
{
	ft_putstr_fd("        ", 1);
	ft_putnbr_fd(get_value(content), 1);
	ft_putstr_fd(":", 1);
	ft_putnbr_fd(get_position(content), 1);
	ft_putstr_fd(":", 1);
	if (get_is_sorted(content) == 1)
		ft_putstr_fd("true", 1);
	else
		ft_putstr_fd("false", 1);
	ft_putstr_fd("\n", 1);
}

void	print_stack_from_tail(t_stack stack)
{
	ft_putstr_fd("        Start stack, size : ", 1);
	ft_putnbr_fd(stack.total_item, 1);
	ft_putstr_fd(", bigger elem ", 1);
	ft_putnbr_fd(stack.bigger_elem, 1);
	ft_putstr_fd("\n", 1);
	if (stack.tail)
		ft_lstdbiter_fun_first_from_back(stack.tail, &print_stack_int);
	ft_putstr_fd("        End stack\n", 1);
}
