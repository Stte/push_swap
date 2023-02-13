#include "unity.h"
#include "push_swap.h"
#include "libft.h"
#include "test.h"

void push_swap_free_stack(t_stack *stack)
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

void get_actual(t_stack *stack, int actual[])
{
	int		i;

	i = 0;
	while (stack != NULL)
	{
		actual[i] = stack->pos;
		stack = stack->next;
		i++;
	}
}

void test_push_swap_three_0(void)
{
	t_stack	*stack = NULL;
	char	*argv[4];
	argv[0] = "NaN";
	argv[1] = "9";
	argv[2] = "2";
	argv[3] = "-3";
	int		expected[] = {0, 1, 2};
	int		actual[3];

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, get_args(&stack, 4, argv), "#1");
	push_swap_three(&stack);
	get_actual(stack, actual);
	TEST_ASSERT_EQUAL_MEMORY(expected, actual, 3 * sizeof(int));
	push_swap_free_stack(stack);
}

int test_push_swap_three(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_push_swap_three_0);
	return UNITY_END();
}
