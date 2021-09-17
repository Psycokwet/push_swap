/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 14:21:04 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_pivot_int(t_list_double *lst, int *arr, int index, int size)
{
	if (!lst || size == index)
		return ;
	arr[index] = get_value(lst->content);
	find_pivot_int(lst->next, arr, index + 1, size);
}

#define FOUND 0
#define NOT_FOUND -1
#define ERROR -2

int	find_index_in_stack(void *test, void *seek)
{
	if (*(int *)seek == get_value(test))
		return (FOUND);
	return (NOT_FOUND);
}

int	pivot_size_from_sorted_side(t_env *env, t_stack stack)
{
	return (ft_lstdbfind_index(stack.head, (void *)&env->position_array[0],
			&find_index_in_stack));
}

void	find_pivot(t_env *env, t_stack stack, int *pivot, int size)
{
	int		*arr;

	if (size < 0)
		error(env, ERROR_NOT_DEFINED);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	{
		free(arr);
		error(env, ERROR_MALLOC);
	}
	find_pivot_int(stack.head, arr, 0, size);
	tri_bulle(arr, size);
	pivot[0] = arr[size / 3];
	pivot[1] = arr[size * 2 / 3];
	free(arr);
}
