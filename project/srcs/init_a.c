/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 15:53:46 by scarboni         ###   ########.fr       */
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
	if (intermediate_result != RETURN_SUCCES
		|| new_value == *(int *)(lst->content))
		return (ERROR_DUPLICATES);
	return (RETURN_SUCCES);
}

static void	parse_one_arg(t_env *env, const char *argv_i)
{
	int		j;
	int		tmp;
	int		is_duplicate;
	t_list	*new_node;
	int		*value;

	j = 0;
	while (ft_isdigit(argv_i[j]))
		j++;
	if (argv_i[j] != '\0')
		error(env, ERROR_NOT_INTEGER);
	tmp = parse_value(env, argv_i);
	is_duplicate = ft_lstiter_duplicates(env, env->a.head, tmp);
	if (is_duplicate != 0)
		error(env, is_duplicate);
	value = (int *)malloc(sizeof(int));
	*value = tmp;
	new_node = ft_lstnew(value);
	ft_lstadd_back(&(env->a.head), new_node);
}

static void	get_ints_from_line(t_env *env, const char *line)
{
	char	**splitted;
	int		i;

	splitted = ft_split(line, ' ');
	if (!splitted[0])
	{
		free(splitted);
		error(env, ERROR_NOT_INTEGER);
	}
	i = 0;
	while (splitted[i])
	{
		parse_one_arg(env, splitted[i]);
		i++;
	}
	free_array(splitted);
	splitted = NULL;
}

void	init_a(t_env *env, const char **argv, int argc)
{
	int		i;

	i = 1;
	env->a.head = NULL;
	while (i < argc)
	{
		get_ints_from_line(env, argv[i]);
		i++;
	}
}
