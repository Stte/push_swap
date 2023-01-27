T = ./tests/

FLAGS = -Wall -Werror -Wextra -g
INCLUDES = -I../inc -I../libft/inc -I./unity
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c ./test.c
TESTS = \
$T/test_validity_checks.c	$T/test_get_args.c	$T/test_btree.c
PUSH_SWAP =
PS := $(filter-out %push_swap.c, $(PUSH_SWAP))

all: clean run_test

run_test:
	gcc $(FLAGS) $(INCLUDES) $(SANITIZE) $(TEST) $(TESTS) $(PS:%=../%) -L../libft -lft -o run_tests
	./run_tests

playground:
	gcc $(FLAGS) $(INCLUDES) $(SANITIZE) playground.c $(PS:%=../%) -L../libft -lft -o run_playground
	./run_playground

clean:
	rm -fr run_*
