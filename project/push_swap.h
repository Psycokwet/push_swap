/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/13 15:15:37 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

# define RETURN_SUCCES			0
# define RETURN_FAILURE			1

# define EXIT_NORMAL			0

# define MAX_ERRORS							4
# define ERROR_NOT_INTEGER					1
# define ERROR_TOO_BIG	   					2
# define ERROR_DUPLICATES					3
# define ERROR_INST_DONT_EXIST_OR_INCORRECT	4

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
	(t_error){ERROR_INST_DONT_EXIST_OR_INCORRECT, "ERROR_INST_DONT_EXIST_OR_INCORRECT",
		"The specified instruction doesn't exist or is incorreclty formatted"},
};

# define ORDERED		0
# define NOT_ORDERED	1

# define MIN_INT	-2147483648

// typedef struct s_node
// {
// 	int				value;
// 	struct s_node	*next;
// }	t_node;

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
}	t_stack;

typedef struct s_env
{
	t_stack	a;
	t_stack	b;
}	t_env;

/*
** ************************************************************************** **
** 									SRCS                                      **
** ************************************************************************** **
*/

int		check_order(t_stack stack);
void	error(t_env *env, int code);
void	free_env(t_env *env);
void	init_a(t_env *env, const char **argv, int argc);
void	init_env(t_env *env, const char **argv, int argc);
void	pa(t_env *env);
void	pb(t_env *env);
void	print_stack(t_stack stack);
void	push(t_stack *giver, t_stack *taker);
void	quit(t_env *env, const char *message, int code, int fd);
void	ra(t_env *env);
void	rb(t_env *env);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	rr(t_env *env);
void	rra(t_env *env);
void	rrb(t_env *env);
void	rrr(t_env *env);
void	sa(t_env *env);
void	sb(t_env *env);
void	ss(t_env *env);
void	switch_front_two(t_stack *stack);

// write
// read
// malloc
// free
// exit

#endif
