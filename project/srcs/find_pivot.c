/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/29 20:57:14 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_pivot_int(t_list_double *lst, int *arr, int index)
{
	if (!lst)
		return ;

	arr[index] = get_value(lst->content);
	find_pivot_int(lst->next, arr, index + 1);
}

void	find_pivot(t_env *env, t_stack stack, t_pivot *pivot)
{
	int		*arr;
	int		size;

	size = stack.total_item;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	{
		free(arr);
		error(env, ERROR_MALLOC);
	}
	find_pivot_int(stack.head, arr, 0);
	tri_bulle(arr, size);
	// printf("pv1 %d:%d\n", arr[size / 3], size / 3);
	// printf("pv2 %d:%d\n", arr[size * 2 / 3], size * 2 / 3);
	pivot->p1 = arr[size / 3];
	pivot->p2 = arr[size * 2/ 3];
	free(arr);
}
