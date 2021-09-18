NAME				=	push_swap
BONUS				=	bonus	
BONUS_EXEC			=	checker_scarboni
MAKE_LIBFT			=	makelibft
LIBFTPATH			=	libft/
LIBFT_AR			=	libft.a

SRC_PATH			= ./srcs/
OBJ_PATH			= bin/
LIBFT_PATH			= libft/

OBJ_PATHS_INIT				= 	$(OBJ_PATH)
## No need for a \ on the last line
HEADERS_FILES				=	push_swap.h
MAIN_FILES					=	main.c
BONUS_FILES					=	bonus.c

SRC_FILES					=	action_stack_brut_force.c			\
								action_stack_optimize_int.c			\
								action_stack_optimize.c			\
								action_stack.c			\
								cell_setters.c					\
								cell.c					\
								check_if_all_bigger.c	\
								check_if_all_bigger_until_i.c	\
								check_order.c			\
								double_action.c			\
								check_order_until_i.c	\
								error.c					\
								find_pivots.c			\
								free_env.c				\
								get_absolute_prev.c		\
								get_absolute_next.c		\
								init_a.c				\
								init_env.c				\
								pa.c					\
								pb.c					\
								position_array.c		\
								print_both_from_tail.c	\
								print_both.c			\
								print_stack_from_tail.c	\
								print_stack.c			\
								push_swap_aborted_1.c				\
								push_swap_aborted_2.c				\
								push_swap_optimize.c				\
								push_swap_small_sorts.c				\
								push_swap.c				\
								push.c					\
								quit.c					\
								ra.c					\
								rb.c					\
								reverse_rotate.c		\
								rotate.c				\
								rr.c					\
								rra.c					\
								rrb.c					\
								rrr.c					\
								sa.c					\
								sb.c					\
								ss.c					\
								start_action_checker.c	\
								start_action_for_optimization.c	\
								start_action_ps_silent.c\
								start_action_ps.c		\
								switch_front_two.c		\
								tri_bulle.c

OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names
OBJMAIN_FILES	= 	$(MAIN_FILES:.c=.o)			## get all .o names from .c names
OBJBONUS_FILES	= 	$(BONUS_FILES:.c=.o)			## get all .o names from .c names

OBJ_FILES = $(OBJREGULAR_FILES)

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
OBJMAIN 		= $(addprefix $(OBJ_PATH), $(OBJMAIN_FILES))
OBJBONUS 		= $(addprefix $(OBJ_PATH), $(OBJBONUS_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -D BUFFER_SIZE=32 -g3 #-Werror  -pedantic 		## '+=' allow to keep default flags.

LDFLAGS		=	-L$(LIBFTPATH) -lft 

RM			= 	rm -f

all					:	 $(OBJ_PATHS_INIT) $(MAKE_LIBFT) $(NAME)


$(LIBFT_PATH)	:
	git clone https://github.com/Psycokwet/libft.git  $(LIBFT_PATH)

$(MAKE_LIBFT)		: $(LIBFT_PATH)
	$(MAKE) -C    $(LIBFT_PATH) $(BONUS)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c $(HEADERS_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)  $(INC) 

$(OBJ_PATHS_INIT)	:
	mkdir -p  $@  

$(NAME)			: 	$(OBJ) $(OBJMAIN) $(addprefix $(LIBFTPATH),$(LIBFT_AR))
	$(CC) -o $(NAME) $(OBJ) $(OBJMAIN) $(LDFLAGS)  $(INC) 

$(BONUS_EXEC)	: 	$(OBJ) $(OBJBONUS) $(addprefix $(LIBFTPATH),$(LIBFT_AR))
	$(CC) -o $(BONUS_EXEC) $(OBJ) $(OBJBONUS)  $(LDFLAGS)  $(INC)

$(BONUS)		: all $(BONUS_EXEC)
		
clean_local		:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)

clean			:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)
	$(MAKE) -C $(LIBFT_PATH) clean	

fclean			:	clean_local							## clean + delete executable
	$(RM) $(NAMETEST) $(NAME) $(BONUS_EXEC)
	$(MAKE) -C $(LIBFT_PATH) fclean					

re				:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY			:	all bonus clean fclean re
## voir dependances plus tard 