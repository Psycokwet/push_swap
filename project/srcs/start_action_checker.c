/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_action_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/14 09:03:46 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	start_action_checker(t_env *env, const char *code)
{
	int	i;

	i = MAX_ACTION_TYPE;
	while (--i >= 0)
	{
		if (ft_strncmp(g_actions_types[i].code.str, code,
				g_actions_types[i].code.size) == 0)
		{
			g_actions_types[i].action(env);
			return (EXIT_ACTION_FOUND);
		}
	}
	return (ERROR_INST_DONT_EXIST_OR_INCORRECT);
}
