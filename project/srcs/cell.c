/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/29 17:14:54 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cell	*new_cell(int value, int position)
{
	t_cell *cell;

	cell = (t_cell *)malloc(sizeof(t_cell));
	cell->value = value;
	cell->position = position;
	return (cell);
}

int get_value(void* content)
{
	return (((t_cell*)content)->value);
}

int get_position(void* content)
{
	return (((t_cell*)content)->position);
}

void set_value(void* content, int value)
{
	((t_cell*)content)->value = value;
}

void set_position(void* content, int position)
{
	((t_cell*)content)->position = position;
}
