NAME 		= push_swap

S			= src/
O			= obj/
I			= inc/
LIBFT_I		= libft/inc

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
INCLUDES	= -I$I -I$(LIBFT_I)
LIBRARIES	= -L./libft -lft

AR			= ar
ARFLAGS		= rcs

SRC = \
$S/main.c				$S/get_args.c			$S/validity_checks.c			\
$S/ft_stack.c			$S/ft_stack_rotates.c	$S/ft_stack_swap.c				\
$S/ft_stack_push.c		$S/push_swap.c			$S/push_swap_three.c			\
$S/push_swap_five.c		$S/do_operation.c		$S/push_swap_utils.c			\
$S/ft_stack_short.c
OBJ			= $(SRC:$S%=$O%.o)

RM			= /bin/rm -f
RMDIR		= /bin/rm -rf

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -g

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

# $(OBJ): | $O

# $(OBJ): $O%.o: $S%
# 	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(SRC)
$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $(SRC) -o $(NAME)

$(LIBFT):
	make FLAGS=$(LIBFT_FLAGS) -C $(LIBFT_DIR)

cleanobjdir: $O
	$(RMDIR) $O

clean: cleanobjdir

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re:
	@make fclean
	@make all

run_test: $(LIBFT)
	make PUSH_SWAP="$(SRC)" -C ./test

playground: $(LIBFT)
	make PUSH_SWAP="$(SRC)" playground -C ./test
