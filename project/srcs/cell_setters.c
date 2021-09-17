/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_setters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 11:01:18 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cell	*new_cell(int value, int position)
{
	t_cell	*cell;

	cell = (t_cell *)malloc(sizeof(t_cell));
	cell->value = value;
	cell->position = position;
	cell->is_sorted = false;
	return (cell);
}

void	set_value(void *content, int value)
{
	((t_cell *)content)->value = value;
}

void	set_position(void *content, int position)
{
	((t_cell *)content)->position = position;
}

void	set_is_sorted(void *content, int is_sorted)
{
	((t_cell *)content)->is_sorted = is_sorted;
}
