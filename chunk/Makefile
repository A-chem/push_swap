NAME = push_swap
CC = cc
CFLAGS =  #-Wall -Wextra -Werror   
SRCS = ./src/push_swap.c ./src/input_valid.c ./src/init_stack.c ./src/sorting.c ./libft_utils/ft_split.c ./libft_utils/ft_isdigit.c ./libft_utils/ft_atoi.c \
		./libft_utils/ft_strlen.c  ./libft_utils/ft_strdup.c ./libft_utils/ft_strjoin.c  ./libft_utils/ft_strchr.c ./utils/memory_management.c  ./utils/sorting_utils_1.c\
		 ./utils/sorting_utils_2.c ./utils/sorting_utils_3.c ./operations/operations_swap.c ./operations/operations_push.c ./operations/operations_rotate.c ./operations/operations_reverse_rotate.c \

OBJS = $(SRCS:.c=.o)

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

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(WORKING) $(CYAN)Compiling: $<$(RESET)"
clean:
	@echo "$(INFO_SIGN) $(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(OK_SIGN) $(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(INFO_SIGN) $(YELLOW)Removing executable: $(NAME)$(RESET)"
	@rm -f $(NAME)
	@echo "$(OK_SIGN) $(GREEN)Executable removed!$(RESET)"

re: fclean all