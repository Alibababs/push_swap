NAME		=	push_swap

CC			=	gcc

FLAG		=	-Wall -Wextra -Werror -g3 -I ./include

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

C_FILE		=	operations/push	 			\
				operations/reverse_rotate	\
				operations/rotate 			\
				operations/swap				\
				push_swap					\
				utils						\
				sort_algo 					\
				sort						\
				sort_utils 					\
				sort_utils2 				\
				parse_args 					\
				parse_args_utils			\

SRC_DIR		=	./srcs/

SRC			=	$(addsuffix .c, $(addprefix $(SRC_DIR),$(C_FILE)))

OBJ			=	$(SRC:.c=.o)

.c.o:
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(LIBFT_LIB):
	@echo "\033[0;33mCOMPILING $(LIBFT_PATH)\n"
	@make -sC $(LIBFT_PATH)
	@echo "\033[1;32mlibft.a created\n"

$(NAME): $(LIBFT_LIB) $(OBJ)
	@echo "\033[0;33mCOMPILING $(NAME)...\n"
	@$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	@echo "\033[1;32m./$(NAME) created\n"

clean:
	@echo "\033[0;31m\nDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting $(NAME) object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting $(NAME) executable...\n"
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

norminette :
	norminette

.PHONY: all clean fclean re norminette
