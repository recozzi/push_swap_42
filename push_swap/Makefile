NAME			:=	push_swap

BONUS_NAME		:=	checker

CC				:=	gcc

CFLAGS			:=	-g -Wall -Wextra -Werror

RM				:=	rm -rf

LIBFT			:=	Libft/libft.a

OBJS_DIR		:=	obj/

SRCS_DIR		:=	src/

SRCS			:=	check_errors.c			\
					check_errors_utils.c	\
					create_stacks.c			\
					single_moves.c			\
					single_moves_utils.c	\
					double_moves.c			\
					small_sort.c			\
					small_sort_utils.c		\
					big_sort.c				\
					big_sort_utils.c		\
					big_sort_utils2.c		\
					free_all.c

OBJS			:=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# COLOR ================================================================= #

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
WHITE = \033[0;97m

# ======================================================================= #

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(GREEN)Compiling:$(WHITE) $<"

all: $(NAME)

$(NAME): lib $(OBJS)
	@$(CC) $(CFLAGS) src/push_swap.c $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}"

lib:
	@make -C Libft

bonus: lib $(OBJS)
	@$(CC) $(CFLAGS) src/checker.c $(OBJS) $(LIBFT) -o $(BONUS_NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C Libft
	@echo "$(RED)All $(CYAN)$(NAME)$(RED)'s objects removed with $(WHITE)${RM} $(YELLOW)"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME) $(OBJS_DIR)
	@make fclean -C Libft
	@echo "$(RED)..and $(CYAN)${NAME} $(RED)as been removed"

re: fclean all

.PHONY: all clean fclean re lib bonus

.SILENT:
