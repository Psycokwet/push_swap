/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/12 23:43:31 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_error
{
	int			error_code;
	const char	*id_error;
	const char	*full_error;
}	t_error;

static const t_error	g_errors[MAX_ERRORS] = {
	(t_error){ERROR_NOT_INTEGER, "ERROR_NOT_INTEGER",
		"One or more inputs are not an integer"},
	(t_error){ERROR_TOO_BIG, "ERROR_TOO_BIG", "One or more inputs is too big"},
	(t_error){ERROR_DUPLICATES, "ERROR_DUPLICATES",
		"There is duplicates in the selection"},
};

void	error(t_env *env, int code)
{
	ft_putstr_fd("Error\n", 2);
	quit(env, g_errors[code - 1].full_error, code, 2);
}
