NAME = push_swap
B_NAME = checker
CC = cc
FLAGS = -Wall -Wextra -Werror -g# -fsanitize=address
RM = rm -f
SRC = src/ps_double_stack_utils.c \
	src/ps_free.c \
	src/ps_info.c \
	src/ps_parse.c \
	src/ps_presort.c \
	src/ps_push_swap.c \
	src/ps_push_to_a.c \
	src/ps_push_to_b.c \
	src/ps_sort_three.c \
	src/ps_sort.c \
	src/ps_stack_utils.c \
	src/ps_stack.c \
	src/ps_utils.c \
	src/instructions/push.c \
	src/instructions/swap.c \
	src/instructions/rotate.c \
	src/instructions/reverse_rotate.c

B_SRC = bonus/ps_double_stack_utils_bonus.c \
	bonus/ps_free_bonus.c \
	bonus/ps_info_bonus.c \
	bonus/ps_parse_bonus.c \
	bonus/ps_presort_bonus.c \
	bonus/ps_push_swap_bonus.c \
	bonus/ps_push_to_a_bonus.c \
	bonus/ps_push_to_b_bonus.c \
	bonus/ps_sort_three_bonus.c \
	bonus/ps_sort_bonus.c \
	bonus/ps_stack_utils_bonus.c \
	bonus/ps_stack_bonus.c \
	bonus/ps_utils_bonus.c \
	bonus/instructions/push_bonus.c \
	bonus/instructions/swap_bonus.c \
	bonus/instructions/rotate_bonus.c \
	bonus/instructions/reverse_rotate_bonus.c

OBJ = $(SRC:src/%.c=obj/%.o)
B_OBJ = $(B_SRC:bonus/%bonus.c=obj/%bonus.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: $(B_NAME)

clean:
	@$(RM) -r obj
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "Cleaned object files\n"

fclean: clean
	@$(RM) $(NAME) $(B_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "Cleaned executables\n"

re: fclean all

$(OBJ): $(SRC) push_swap.h Makefile
	@mkdir -p $(dir $@)
	@printf "Building $@\n"
	@$(CC) $(FLAGS) -c $(@:obj/%.o=src/%.c) -o $@

$(B_OBJ): $(B_SRC) push_swap_bonus.h Makefile
	@mkdir -p $(dir $(OBJ))
	@printf "Building $@\n"
	@$(CC) $(FLAGS) -c $(@:obj/%bonus.o=bonus/%bonus.c) -o $@

$(NAME): $(LIBFT) $(OBJ)
	@printf "Compiling\n"
	@$(CC) $(FLAGS) $(OBJ) -L $(LIBFT_DIR) -lft -o $(NAME) #The -l flag prepends "lib"- to the library, so technically you look for "ft"
	@printf "Done\n"

$(B_NAME): $(LIBFT) $(B_OBJ)
	@printf "Compiling\n"
	@$(CC) $(FLAGS) $(B_OBJ) -L $(LIBFT_DIR) -lft -o $(B_NAME)
	@printf "Done\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: libft all re clean fclean