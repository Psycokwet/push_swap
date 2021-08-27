/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/22 19:53:05 by scarboni         ###   ########.fr       */
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

# define MAX_ERRORS							5
# define ERROR_NOT_INTEGER					1
# define ERROR_TOO_BIG	   					2
# define ERROR_DUPLICATES					3
# define ERROR_INST_DONT_EXIST_OR_INCORRECT	4
# define ERROR_MALLOC						5


typedef struct s_error
{
	int			error_code;
	const char	*id_error;
	const char	*full_error;
}	t_error;

static const t_error		g_errors[MAX_ERRORS] = {
	(t_error){ERROR_NOT_INTEGER, "ERROR_NOT_INTEGER",
		"One or more inputs are not an integer"},
	(t_error){ERROR_TOO_BIG, "ERROR_TOO_BIG", "One or more inputs is too big"},
	(t_error){ERROR_DUPLICATES, "ERROR_DUPLICATES",
		"There is duplicates in the selection"},
	(t_error){ERROR_INST_DONT_EXIST_OR_INCORRECT,
		"ERROR_INST_DONT_EXIST_OR_INCORRECT",
		"The specified instruction doesn't exist or is incorreclty formatted"},
	(t_error){ERROR_MALLOC,
		"ERROR_MALLOC",
		"Local malloc didn't work for some reason"},
};

# define ORDERED			0
# define NOT_ORDERED		1
# define ONLY_BIGGER		1
# define MISC				0
# define NO_ACTION_DONE		0
# define ACTION_DONE		1
# define INCOMPLETE_ACTION	2

# define MIN_INT	-2147483648

// typedef struct s_node
// {
// 	int				value;
// 	struct s_node	*next;
// }	t_node;

typedef struct s_stack
{
	t_list	*head;
	int		total_item;
}	t_stack;

typedef struct s_env
{
	t_stack	a;
	t_stack	b;
	t_stack	c_a;
	t_stack	c_b;
	int		total_item;
	t_stack	action_stack;
	int		pivot1;
	int		pivot2;
	int		*position_array;
}	t_env;

typedef struct s_str
{
	char	*str;
	size_t	size;
}			t_str;

/*
** ************************************************************************** **
** 									SRCS                                      **
** ************************************************************************** **
*/

int		check_if_all_bigger(t_stack stack, int threshold);
int		check_order(t_stack stack);
void	error(t_env *env, int code);
void	find_pivot(t_env *env, t_stack stack);
void	free_env(t_env *env);
void	init_a(t_env *env, const char **argv, int argc);
void	init_env(t_env *env, const char **argv, int argc);
int		pa(t_env *env);
int		pb(t_env *env);
int		print_both(t_env *env);
void	print_stack(t_stack stack);
void	push_swap(t_env *env);
int		push(t_stack *giver, t_stack *taker);
void	quit(t_env *env, const char *message, int code, int fd);
int		ra(t_env *env);
int		rb(t_env *env);
int		reverse_rotate(t_stack *stack);
int		rotate(t_stack *stack);
int		rr(t_env *env);
int		rra(t_env *env);
int		rrb(t_env *env);
int		rrr(t_env *env);
int		sa(t_env *env);
int		sb(t_env *env);
int		ss(t_env *env);
int		start_action_checker(t_env *env, const char *code);
int		start_action_ps_silent(t_env *env, int index);
int		start_action_ps(t_env *env, int index);
int		switch_front_two(t_stack *stack);
void	tri_bulle(int *arr, int size);

void	optimise_action_stack(t_env *env);
void	execute_action_stack(t_env *env, int (*fun)(t_env*, int));
void	add_back_action_stack(t_env *env, int full_id);
void	clear_action_stack(t_env *env);
void	fake_free(void* content);
void	print_action_stack(t_env* env);
void	upgrade_to_next_possibility(t_env *env);

# define MAX_ACTION_TYPE		12
# define EXIT_ACTION_FOUND		0

typedef struct s_action_type
{
	t_str	code;
	int	(*action)(t_env	*);
}	t_action_type;

# define ACT_ID_S_		0
# define ACT_ID__A		0
# define ACT_ID__B		1
# define ACT_ID_SS		2
# define ACT_ID_P_		3
# define ACT_ID_R_		5
# define ACT_ID_RR		7
# define ACT_ID_RR_		8
# define ACT_ID_RRR		10
# define ACT_ID_PRINT	11

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

// write
// read
// malloc
// free
// exit

#endif
