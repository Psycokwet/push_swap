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

SRC_FILES					=	check_order.c	\
								error.c			\
								free_env.c		\
								init_a.c		\
								init_env.c		\
								pa.c			\
								pb.c			\
								print_stack.c	\
								push.c			\
								quit.c			\
								ra.c			\
								rb.c			\
								reverse_rotate.c\
								rotate.c		\
								rr.c			\
								rra.c			\
								rrb.c			\
								rrr.c			\
								sa.c			\
								sb.c			\
								ss.c			\
								switch_front_two.c

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