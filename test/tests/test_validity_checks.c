#include "unity.h"
#include "push_swap.h"
#include "libft.h"

void valid_free_stack(t_stack *stack)
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

void test_is_unique_num_0(void)
{
	t_stack	*stack;
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = ft_stack(1);
	node2 = ft_stack(2);
	node3 = ft_stack(3);
	stack = node1;

	ft_stack_append(&stack, &node2);
	ft_stack_append(&stack, &node3);

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, is_unique_num(stack, 4), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, is_unique_num(stack, -4), "#2");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, is_unique_num(stack, 2), "#3");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, is_unique_num(NULL, 2), "#4");
	valid_free_stack(stack);
}

void test_is_valid_num_0(void)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, is_valid_num("123"), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, is_valid_num("-123"), "#2");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, is_valid_num(""), "#3");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, is_valid_num(NULL), "#4");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, is_valid_num(" "), "#5");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, is_valid_num("123abc"), "#6");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, is_valid_num("abc123"), "#7");
}


int test_validity(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_is_unique_num_0);
	RUN_TEST(test_is_valid_num_0);
	return UNITY_END();
}
