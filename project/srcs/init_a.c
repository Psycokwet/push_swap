/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 01:20:14 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_value(t_env *env, char const *arg)
{
	int				tmp;
	char			*checker;
	unsigned int	checker_length;

	if (arg == NULL)
		return (-EXIT_FAILURE);
	tmp = ft_atoi(arg);
	checker = ft_itoa(tmp);
	checker_length = ft_strlen(checker);
	if (!(ft_strncmp(arg, checker,
				checker_length) == 0 && ft_strlen(arg) == checker_length))
	{
		free(checker);
		error(env, ERROR_TOO_BIG);
		return (-EXIT_FAILURE);
	}
	free(checker);
	return (tmp);
}

void	init_a(t_env *env, const char **argv, int argc)
{
	int	i;
	int	j;
	int tmp;

	i = 1;
	env->a.head = NULL;
	env->a.tail = NULL;
	while (i < argc)
	{
		j = 0;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] != '\0')
			error(env, ERROR_NOT_INTEGER);
		tmp =  parse_value(env, argv[i]);
		printf("%d result\n", tmp);
		int *value = (int *)malloc(sizeof(int));
		*value = tmp;
		ft_lstadd_back(&(env->a.head), ft_lstnew(value));
		i++;
	}
	print_stack(env->a);
}
