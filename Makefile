GREEN=\033[1;32m
RED=\033[0;31m
BLUE=\033[0;34m

NAME		=	push_swap

BONUS_NAME	=	checker

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3 -I ./includes

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

BONUS_FILE	=	../srcs_bonus/checker		\
				../srcs_bonus/checker_utils	\
				operations/push	 			\
				operations/reverse_rotate	\
				operations/rotate 			\
				operations/swap				\
				utils						\
				sort_algo 					\
				sort						\
				sort_utils 					\
				sort_utils2 				\
				parse_args 					\
				parse_args_utils			\

SRC_DIR		=	./srcs/

SRC			=	$(addsuffix .c, $(addprefix $(SRC_DIR),$(C_FILE)))

BONUS_SRC	=	$(addsuffix .c, $(addprefix $(SRC_DIR),$(BONUS_FILE)))

OBJ			=	$(SRC:.c=.o)

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

.c.o:
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT_LIB):
	@echo "$(BLUE)COMPILING $(LIBFT_PATH)\n"
	@make -sC $(LIBFT_PATH)
	@echo "$(GREEN)libft.a created\n"

$(NAME): $(LIBFT_LIB) $(OBJ)
	@echo "$(BLUE)COMPILING $(NAME)...\n"
	@$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)./$(NAME) created\n"

$(BONUS_NAME): $(LIBFT_LIB) $(BONUS_OBJ)
	@echo "$(BLUE)COMPILING $(BONUS_NAME)...\n"
	@$(CC) $(BONUS_OBJ) $(LIBFT_LIB) -o $(BONUS_NAME)
	@echo "$(GREEN)./$(BONUS_NAME) created\n"

clean:
	@echo "$(RED)\nDeleting obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "$(GREEN)Done\n"
	@echo "$(RED)Deleting $(NAME) object...\n"
	@rm -f $(OBJ)
	@echo "$(GREEN)Done\n"
	@echo "$(RED)Deleting $(BONUS_NAME) object...\n"
	@rm -f $(BONUS_OBJ)
	@echo "$(GREEN)Done\n"

fclean: clean
	@echo "$(RED)Deleting $(NAME) executable...\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@make fclean -sC $(LIBFT_PATH)
	@echo "$(GREEN)Done\n"

re: fclean all

.PHONY: all clean fclean re
