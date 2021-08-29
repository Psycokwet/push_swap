/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/29 17:15:37 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_position_array(t_env *env)
{
	int i;

	i = 0;
	while(i < env->total_item)
	{
		printf("[%d]:%d ", i, env->position_array[i]);
		i++;
	}
	printf("\n");
}

int		find_index_of(t_env* env, int value)
{
	int i;

	i = 0;
	while (i < env->total_item)
	{
		if (value == env->position_array[i])
			return (i);
		i++;
	}
	return (-EXIT_FAILURE);
}

void	init_position_array(t_env *env)
{
	t_list_double	*item;
	int		i;

	env->position_array = (int *)malloc(sizeof(int) * env->total_item);
	i = 0;
	item = env->a.head;
	while(item){
		env->position_array[i] = get_value(item->content);
		item = item->next;
		i++;
	}
	// print_position_array(env);
	tri_bulle(env->position_array, env->total_item);
	// print_position_array(env);

	item = env->a.head;
	while(item){
		set_position(item->content, find_index_of(env, get_value(item->content)));
		item = item->next;
	}
}
