/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/17 11:12:05 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_value(t_env *env, char const *arg, char **splitted)
{
	int				tmp;
	char			*checker;
	unsigned int	checker_length;

	if (arg == NULL)
	{
		free_array(splitted);
		error(env, ERROR_NOT_INTEGER);
	}
	tmp = ft_atoi(arg);
	checker = ft_itoa(tmp);
	checker_length = ft_strlen(checker);
	if (!(ft_strncmp(arg, checker,
				checker_length) == 0 && ft_strlen(arg) == checker_length))
	{
		free(checker);
		free_array(splitted);
		error(env, ERROR_TOO_BIG);
	}
	free(checker);
	return (tmp);
}

static int	ft_lstdbiter_duplicates(t_env *env, t_list_double *lst,
int new_value)
{
	int	intermediate_result;

	if (!lst)
		return (RETURN_SUCCES);
	intermediate_result = ft_lstdbiter_duplicates(env, lst->next, new_value);
	if (intermediate_result != RETURN_SUCCES
		|| new_value == *(int *)(lst->content))
		return (ERROR_DUPLICATES);
	return (RETURN_SUCCES);
}

static int	parse_one_arg(t_env *env, const char *argv_i, char **splitted)
{
	int				j;
	int				tmp;
	int				is_duplicate;
	t_list_double	*new_node;
	t_cell			*cell;

	j = 0;
	while (ft_isdigit(argv_i[j]))
		j++;
	if (argv_i[j] != '\0' && argv_i[j] != '-')
		return (ERROR_NOT_INTEGER);
	tmp = parse_value(env, argv_i, splitted);
	is_duplicate = ft_lstdbiter_duplicates(env, env->a.head, tmp);
	if (is_duplicate != EXIT_SUCCESS)
		return (is_duplicate);
	cell = new_cell(tmp, -1);
	new_node = ft_lstdbnew(cell);
	env->total_item++;
	ft_lstdbadd_back(&(env->a.head), new_node);
	if (env->a.tail)
		new_node->prev = env->a.tail;
	if (get_value(new_node->content) > env->a.bigger_elem)
		env->a.bigger_elem = get_value(new_node->content);
	env->a.tail = new_node;
	return (EXIT_SUCCESS);
}

static void	get_ints_from_line(t_env *env, const char *line)
{
	char	**splitted;
	int		i;
	int		ret;

	splitted = ft_split(line, ' ');
	if (!splitted[0])
	{
		free(splitted);
		error(env, ERROR_NOT_INTEGER);
	}
	i = 0;
	while (splitted[i])
	{
		ret = parse_one_arg(env, splitted[i], splitted);
		if (ret != EXIT_SUCCESS)
		{
			free_array(splitted);
			error(env, ret);
		}
		i++;
	}
	free_array(splitted);
	splitted = NULL;
}

void	init_a(t_env *env, const char **argv, int argc)
{
	int		i;

	i = 1;
	env->total_item = 0;
	env->a.head = NULL;
	while (i < argc)
	{
		get_ints_from_line(env, argv[i]);
		i++;
	}
	env->a.total_item = env->total_item;
}
