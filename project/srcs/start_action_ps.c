/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_action_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/16 11:08:43 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	start_action_ps(t_env *env, int index)
{
	if (index >= MAX_ACTION_TYPE)
		error(env, ERROR_INST_DONT_EXIST_OR_INCORRECT);
	int tmp = g_actions_types[index].action(env);
	if(tmp == INCOMPLETE_ACTION || tmp == ACTION_DONE)
	{
		ft_putstr_fd(g_actions_types[index].code.str, 1);
		ft_putstr_fd("\n", 1);
	}
	// else{
	// 	ft_putstr_fd(g_actions_types[index].code.str, 1);
	// 	ft_putstr_fd("---ERRORED ACTION\n", 1);
	// 	print_both(env);
	// }
	// else// if(index == ACT_ID__A + ACT_ID_S_)
	// {
	// 	printf("FAILED ACTION %s:%d\n", g_actions_types[index].code.str, tmp);
	// 	print_both(env);
	// }
	
	// ft_putstr_fd("RESULT ACTION ", 1);
	// ft_putstr_fd(g_actions_types[index].code.str, 1);
	// ft_putnbr_fd(tmp, 1);
	// ft_putstr_fd("\n", 1);
	// print_both(env);
	return (1);
}
