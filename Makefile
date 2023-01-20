NAME 		= push_swap

S			= src/
O			= obj/
I			= inc/
LIBFT_I		= libft/inc

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I$I -I$(LIBFT_I) -g

AR			= ar
ARFLAGS		= rcs

SRC = \
$S/push_swap.c	$S/get_args.c
OBJ			= $(SRC:$S%=$O%.o)

RM			= /bin/rm -f
RMDIR		= /bin/rm -rf

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	$(CC) $(CFLAGS) $< -o $@

# $(NAME): $(OBJ)
$(NAME):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) libft.a
	$(CC) $(CFLAGS) -L. -lft $(SRC) -o push_swap

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

cleanobjdir: $O
	$(RMDIR) $O

clean: cleanobjdir

fclean: clean
	# make fclean -C libft
	$(RM) $(NAME)

re:
	@make fclean
	@make all
