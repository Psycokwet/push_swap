/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/29 17:04:39 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/get_next_line.h"

static int	print_result(t_env *env)
{
	if (env->b.head == NULL && check_order(env->a) == ORDERED)
		printf("OK\n");
	else
		printf("KO\n");
	free_env(env);
	return (EXIT_SUCCESS);
}

int	main(int argc, const char **argv)
{
	t_env	env;
	char	*line2;
	int		ret;
	int		ret_action;

	init_env(&env, argv, argc);

	init_position_array(&env);
	if (!env.a.head)
		return (EXIT_SUCCESS);
	line2 = NULL;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(STDIN_FILENO, &line2);
		if (ret == EXIT_READ_CLOSED)
		{
			free(line2);
			break ;
		}
		ret_action = start_action_checker(&env, line2);
		free(line2);
		if (ret_action != EXIT_ACTION_FOUND)
			error(&env, ret_action);
	}
	return (print_result(&env));
}
