/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/10/17 18:01:54 by scarboni         ###   ########.fr       */
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

# define MAX_ERRORS							6
# define ERROR_NOT_INTEGER					1
# define ERROR_TOO_BIG	   					2
# define ERROR_DUPLICATES					3
# define ERROR_INST_DONT_EXIST_OR_INCORRECT	4
# define ERROR_MALLOC						5
# define ERROR_NOT_DEFINED					6

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
	(t_error){ERROR_NOT_DEFINED,
		"ERROR_NOT_DEFINED",
		"Not defined"},
};

# define ORDERED			0
# define NOT_ORDERED		1
# define ONLY_BIGGER		1
# define MISC				0
# define NO_ACTION_DONE		0
# define ACTION_DONE		1
# define INCOMPLETE_ACTION	2

# define MIN_INT	-2147483648

typedef struct s_pivot
{
	int				p1;
	int				p2;
}	t_pivot;

typedef struct s_cell
{
	int				value;
	int				position;
	int				is_sorted;
}	t_cell;

typedef struct s_stack
{
	t_list_double	*head;
	t_list_double	*tail;
	int				total_item;
	int				bigger_elem;
}	t_stack;

typedef struct s_str
{
	char	*str;
	size_t	size;
}			t_str;

typedef struct s_couple
{
	int		seek;
	int		found;
	int		replacement;
}			t_couple;

# define MAX_COUPLES			3

typedef struct s_env
{
	t_stack		a;
	t_stack		b;
	t_stack		c_a;
	t_stack		c_b;
	t_pivot		pa;
	t_pivot		pb;
	int			total_item;
	t_stack		action_stack;
	int			*position_array;
	t_couple	couples[MAX_COUPLES];
}	t_env;

/*
** ************************************************************************** **
** 									SRCS                                      **
** ************************************************************************** **
*/

int				check_if_all_bigger(t_stack stack, int threshold);
int				check_if_all_bigger_until_i(t_stack stack, int threshold,
					int i);
int				check_order(t_stack stack);
int				double_action(t_env *env, int (*fun_a)(t_env*),
					int (*fun_b)(t_env*));
int				check_order_until_i(t_stack stack, int i);
void			error(t_env *env, int code);
int				pivot_size_from_sorted_side(t_env *env, t_stack stack);
void			find_pivots(t_env *env, t_stack stack, int *pivot, int size);
void			free_env(t_env *env);
t_list_double	*get_absolute_prev(t_stack *stack, t_list_double *elem);
t_list_double	*get_absolute_next(t_stack *stack, t_list_double *elem);
void			init_a(t_env *env, const char **argv, int argc);
void			init_env(t_env *env, const char **argv, int argc);
int				pa(t_env *env);
int				pb(t_env *env);
int				print_both_from_tail(t_env *env);
int				print_both(t_env *env);
void			print_stack_from_tail(t_stack stack);
void			print_stack(t_stack stack);
void			push_swap(t_env *env);
int				push(t_stack *giver, t_stack *taker);
void			quit(t_env *env, const char *message, int code, int fd);
int				ra(t_env *env);
int				rb(t_env *env);
int				reverse_rotate(t_stack *stack);
int				rotate(t_stack *stack);
int				rr(t_env *env);
int				rra(t_env *env);
int				rrb(t_env *env);
int				rrr(t_env *env);
int				sa(t_env *env);
int				sb(t_env *env);
int				ss(t_env *env);
int				start_action_checker(t_env *env, const char *code);
int				start_action_for_optimization(t_env *env, int index);
int				start_action_ps_silent(t_env *env, int index);
int				start_action_ps(t_env *env, int index);
int				switch_front_two(t_stack *stack);
void			tri_bulle(int *arr, int size);

void			optimise_action_stack(t_env *env);
void			execute_action_stack(t_env *env, int (*fun)(t_env*, int));
void			add_back_action_stack(t_env *env, int full_id);
void			clear_action_stack(t_env *env);
void			print_action_stack(t_env *env);
void			upgrade_to_next_possibility(t_env *env);

t_cell			*new_cell(int value, int position);
int				get_value(void *content);
int				get_position(void *content);
void			set_value(void *content, int value);
void			set_position(void *content, int position);
int				get_is_sorted(void *content);
void			set_is_sorted(void *content, int is_sorted);

void			print_position_array(t_env *env);
int				find_index_of(t_env *env, int value);
void			init_position_array(t_env *env);

void			sort_three(t_env *env, t_stack stack, int base_id,
					int (*fun)(t_env *, int));
void			sort_two(t_env *env, t_stack stack, int base_id,
					int (*fun)(t_env *, int));
void			sort_five(t_env *env, int (*fun)(t_env *, int));
int				find_position(t_stack stack);
void			switch_position(t_env *env, t_stack stack, int id_stack,
					int (*fun)(t_env*, int));
void			*copy_content(void *src, void *dst);
void			reset_a_and_b(t_env *env);
void			start_brute_force(t_env *env);
void			rotate_while_sorted(t_env *env, t_stack *stack,
					int (*fun)(t_env*, int));
void			validate_sorted_elem(t_env *env, t_stack *stack,
					t_list_double *elem);
void			validate_sorted_stack(t_env *env);
void			push_if_sorted(t_env *env, int (*fun)(t_env*, int));
void			b_to_a(t_env *env, int (*fun)(t_env*, int));
void			algo(t_env *env, int (*fun)(t_env*, int));
void			sort_a_to_b(t_env *env, int counter,
					int (*fun)(t_env *, int));
void			sort_b_to_a(t_env *env, int counter,
					int (*fun)(t_env *, int));
void			roll_back_to_order(t_env *env, int *counters,
					int (*fun)(t_env *, int));
void			sort_b_up_to_2(t_env *env, int counter,
					int (*fun)(t_env *, int));
void			init_couples(t_env *env);
int				test_couple(t_env *env, t_list_double *current, int index);
void			try_to_fill_couple(t_env *env, t_list_double *current,
					int index);
void			optimise_action_from_node(t_env *env, t_list_double *current);

# define MAX_ACTION_TYPE		13
# define EXIT_ACTION_FOUND		0

typedef struct s_action_type
{
	t_str	code;
	int		(*action)(t_env	*);
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
# define ACT_ID_PRINT_T	12

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
	(t_action_type){(t_str){"print_t", 7}, &print_both_from_tail},
};

// write
// read
// malloc
// free
// exit

#endif
