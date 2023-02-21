#include "unity.h"
#include "push_swap.h"
#include "libft.h"

void args_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack->next != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
}

void test_get_args_0(void)
{
	t_stack	*stack = NULL;
	char	*argv[6];
	argv[0] = "NaN";
	argv[1] = "9";
	argv[2] = "2";
	argv[3] = "-3";
	argv[4] = "0";
	argv[5] = "100";
	int		expected[] = {4, 3, 1, 2, 5};
	int		actual[5];
	int		i;
	t_stack	*head;


	TEST_ASSERT_EQUAL_INT_MESSAGE(1, get_args(&stack, 6, argv), "#1");
	head = stack;
	i = 0;
	while (stack != NULL)
	{
		actual[i] = stack->pos;
		stack = stack->next;
		i++;
	}
	TEST_ASSERT_EQUAL_MEMORY(expected, actual, 5*4);
	args_free_stack(head);
}

int test_get_args(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_args_0);
	return UNITY_END();
}
