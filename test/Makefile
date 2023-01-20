FLAGS = -Wall -Werror -Wextra -g -I../inc -I../libft/inc
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c
GET_ARGS_TEST = ./test_get_args.c ../src/get_args.c

all: build get_args

build:
	make -C ..

get_args:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(GET_ARGS_TEST) -L../libft -lft -o run_get_args
	./run_get_args

# playground:
# 	$(CC) $(FLAGS) $(SANITIZE) playground.c -L.. -lft -o run_playground
# 	./run_playground

clean:
	rm -fr run_*
