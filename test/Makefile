FLAGS = -Wall -Werror -Wextra -g -I../inc -I../libft/inc
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c
GET_ARGS_TEST = ./test_get_args.c
VALIDIDY_CHECKER_TEST = ./test_validity_checks.c
PUSH_SWAP =
PS := $(filter-out %push_swap.c, $(PUSH_SWAP))


all: clean validity_checks get_args

validity_checks:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(VALIDIDY_CHECKER_TEST) $(PS:%=../%) -L../libft -lft -o run_validity_checks
	./run_validity_checks

get_args:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(GET_ARGS_TEST) $(PS:%=../%) -L../libft -lft -o run_get_args
	./run_get_args

playground:
	gcc $(FLAGS) $(SANITIZE) playground.c $(PS:%=../%) -L../libft -lft -o run_playground
	./run_playground

clean:
	rm -fr run_*
