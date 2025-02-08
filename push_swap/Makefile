NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS =#-Wall -Wextra -Werror

SRCS = ./Mandatory/src/push_swap.c ./Mandatory/src/input_valid.c ./Mandatory/src/init_stack.c ./Mandatory/src/sorting.c ./Mandatory/libft_utils/ft_split.c ./Mandatory/libft_utils/ft_isdigit.c ./Mandatory/libft_utils/ft_atoi.c \
		./Mandatory/libft_utils/ft_strlen.c  ./Mandatory/libft_utils/ft_strdup.c ./Mandatory/libft_utils/ft_strjoin.c  ./Mandatory/libft_utils/ft_strchr.c ./Mandatory/utils/memory_management.c  ./Mandatory/utils/sorting_utils_1.c\
		 ./Mandatory/utils/sorting_utils_2.c ./Mandatory/utils/sorting_utils_3.c ./Mandatory/operations/operations_swap.c ./Mandatory/operations/operations_push.c ./Mandatory/operations/operations_rotate.c ./Mandatory/operations/operations_reverse_rotate.c \

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ./Bonus/src/checker_bonus.c   ./Bonus/src/input_valid_bonus.c  ./Bonus/src/read_execution_bonus.c  ./Bonus/src/init_stack_bonus.c   ./Bonus/libft_utils_bonus/ft_split_bonus.c  ./Bonus/libft_utils_bonus/ft_atoi_bonus.c  ./Bonus/libft_utils_bonus/ft_isdigit_bonus.c \
		     ./Bonus/libft_utils_bonus/ft_strncmp_bonus.c ./Bonus/operations_bonus/operations_swap_bonus.c  ./Bonus/operations_bonus/operations_push_bonus.c  ./Bonus/operations_bonus/operations_rotate_bonus.c  ./Bonus/operations_bonus/operations_reverse_rotate_bonus.c  ./Bonus/utils_bonus/memory_management_bonus.c  \
			 ./Bonus/get_next_line_bonus/get_next_line_bonus.c  ./Bonus/get_next_line_bonus/get_next_line_utils_bonus.c  \

BONUS_OBJS = $(SRCS_BONUS:.c=.o)

GREEN       := \033[32m
YELLOW      := \033[33m
CYAN        := \033[36m
RESET       := \033[0m
OK_SIGN     := ✅
ERROR_SIGN  := ❌
INFO_SIGN   := ℹ️
WORKING     := 🔧

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(OK_SIGN) $(GREEN)Compilation complete!$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)
	@echo "$(OK_SIGN) $(GREEN)Compilation complete for bonus!$(RESET)"

./Mandatory/%.o: ./Mandatory/%.c ./Mandatory/include/push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(WORKING) $(CYAN)Compiling: $<$(RESET)"

./Bonus/%.o: ./Bonus/%.c ./Bonus/include/checker_bonus.h ./Bonus/include/get_next_line.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(WORKING) $(CYAN)Compiling: $<$(RESET)"

clean:
	@echo "$(INFO_SIGN) $(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "$(OK_SIGN) $(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(INFO_SIGN) $(YELLOW)Removing executables: $(NAME) and $(NAME_BONUS)$(RESET)"
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(OK_SIGN) $(GREEN)Executables removed!$(RESET)"

re: fclean all
