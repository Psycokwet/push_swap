/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 15:44:37 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/get_next_line.h"

#define MAX_ACTION_TYPE			12
#define EXIT_ACTION_FOUND		0

typedef struct			s_str
{
	char				*str;
	size_t				size;
}						t_str;

typedef struct s_action_type
{
	t_str	code;
	void	(*action)(t_env	*);
}	t_action_type;

static void print_both(t_env *env)
{
	print_stack(env->a);
	print_stack(env->b);
}

static const t_action_type	g_actions_types[MAX_ACTION_TYPE] = {
	(t_action_type){(t_str){"sa", 2}, &sa},
	(t_action_type){(t_str){"sb", 2}, &sb},
	(t_action_type){(t_str){"ss", 2}, &ss},
	(t_action_type){(t_str){"pa", 2}, &pa},
	(t_action_type){(t_str){"pb", 2}, &pb},
	(t_action_type){(t_str){"ra", 2}, &ra},
	(t_action_type){(t_str){"rb", 2}, &rb},
	(t_action_type){(t_str){"rr", 2}, &rr},
	(t_action_type){(t_str){"rra", 3}, &rra},
	(t_action_type){(t_str){"rrb", 3}, &rrb},
	(t_action_type){(t_str){"rrr", 3}, &rrr},
	(t_action_type){(t_str){"print", 5}, &print_both},
};

static int	start_action(t_env *env, const char *code)
{
	int i;

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

int         main(int argc, const char **argv)
{
	t_env	env;
	char	*line2;
	int		ret;
	int		ret_action;

	init_env(&env, argv, argc);
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
			break;
		}
		ret_action = start_action(&env, line2);
		free(line2);
		if (ret_action != EXIT_ACTION_FOUND)
			error(&env, ret_action);
		
	}
	if (env.b.head == NULL && check_order(*(&env.a)) == ORDERED)
		printf("OK\n");
	else
		printf("KO\n");
	free_env(&env);
	return (EXIT_SUCCESS);
}
