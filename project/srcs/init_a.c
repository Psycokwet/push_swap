/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 11:01:56 by scarboni         ###   ########.fr       */
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


static int	ft_lstiter_duplicates(t_env *env, t_list *lst, int new_value)
{
	int	intermediate_result;

	if (!lst)
		return (RETURN_SUCCES);
	intermediate_result = ft_lstiter_duplicates(env, lst->next, new_value);
	if(intermediate_result != RETURN_SUCCES || new_value == *(int*)(lst->content))
		return (ERROR_DUPLICATES);
	return (RETURN_SUCCES);
}


void	init_a(t_env *env, const char **argv, int argc)
{
	int	i;
	int	j;
	int tmp;
	int is_duplicate;
	t_list *new_node;

	i = 1;
	env->a.head = NULL;
	while (i < argc)
	{
		j = 0;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] != '\0')
			error(env, ERROR_NOT_INTEGER);
		tmp =  parse_value(env, argv[i]);
		is_duplicate = ft_lstiter_duplicates(env, env->a.head, tmp);
		if(is_duplicate != 0)
			error(env, is_duplicate);
		int *value = (int *)malloc(sizeof(int));
		*value = tmp;
		new_node = ft_lstnew(value);
		ft_lstadd_back(&(env->a.head), new_node);
		i++;
	}
	print_stack(env->a);
	sa(env);
	print_stack(env->a);
	print_stack(env->b);
	sb(env);
	print_stack(env->b);
	ss(env);

	print_stack(env->a);
	print_stack(env->b);
	pb(env);
	print_stack(env->a);
	print_stack(env->b);
	pa(env);
	print_stack(env->a);
	print_stack(env->b);
	rr(env);
	print_stack(env->a);
	print_stack(env->b);
}
