/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 15:06:52 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/get_next_line.h"

#define MAX_ACTION_TYPE 11

typedef struct s_action_type
{
	const char	*name;
	void	(*action)(t_env	*);
}	t_action_type;

static const t_action_type	g_actions_types[MAX_ACTION_TYPE] = {
	(t_action_type){"sa", &sa},
	(t_action_type){"sb", &sb},
	(t_action_type){"ss", &ss},
	(t_action_type){"pa", &pa},
	(t_action_type){"pb", &pb},
	(t_action_type){"ra", &ra},
	(t_action_type){"rb", &rb},
	(t_action_type){"rr", &rr},
	(t_action_type){"rra", &rra},
	(t_action_type){"rrb", &rrb},
	(t_action_type){"rrr", &rrr},
};

int         main(int argc, const char **argv)
{
	t_env	env;

	init_env(&env, argv, argc);
	char * line2 = NULL;
	int ret = 1;

	while (ret == 1){
		if(env.b.head == NULL && check_order(*(&env.a)) == ORDERED)
		{
			printf("OK\n");
			free_env(&env);
			free(line2);
			return (EXIT_SUCCESS);
		}
		// else 
		// {
		// 	print_stack(*(&env.a));
		// 	print_stack(*(&env.b));
		// }
		ret = get_next_line(STDIN_FILENO, &line2);
		printf("[%d][%s]\n", ret , line2); //debug
		free(line2);
	}
	if(env.b.head == NULL && check_order(*(&env.a)) == ORDERED)
		printf("OK\n");
	else
		printf("KO\n");
	free_env(&env);
	return (EXIT_SUCCESS);
}
