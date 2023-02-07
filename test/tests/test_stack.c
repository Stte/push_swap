#include "unity.h"
#include "push_swap.h"
#include "libft.h"

void test_ft_stack_0(void)
{
	t_stack *stack;

	stack = ft_stack(42);
	TEST_ASSERT_TRUE_MESSAGE(stack != NULL, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stack->content == 42, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stack->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stack->prev == NULL, "#4");
}

void test_ft_stack_1(void)
{
	t_stack	*stack;

	stack = ft_stack(42);
	TEST_ASSERT_TRUE_MESSAGE(stack != NULL, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stack->content == 42, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stack->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stack->prev == NULL, "#4");
}

void test_ft_stack_append_0(void)
{
	t_stack	*stack;
	t_stack	*stack2;
	t_stack	*stack3;

	stack = ft_stack(1);
	stack2 = ft_stack(2);
	stack3 = ft_stack(3);

	// NULL <- stack <-> stack2 -> NULL
	ft_stack_append(stack, stack2);
	TEST_ASSERT_TRUE_MESSAGE(stack->next == stack2, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stack->next->next == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stack->next->prev == stack, "#3");
	// NULL <- stack <-> stack2 <-> stack3 -> NULL
	ft_stack_append(stack, stack3);
	TEST_ASSERT_TRUE_MESSAGE(stack->next == stack2, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stack->next->next == stack3, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stack->next->next->prev == stack2, "#3");
}

void test_ft_stack_prepend_0(void)
{
	t_stack	*stack;
	t_stack	*stack2;
	t_stack	*stack3;
	t_stack *head;

	stack = ft_stack(1);
	stack2 = ft_stack(2);
	stack3 = ft_stack(3);
	head = stack;

	// NULL <- stack2 <-> stack -> NULL
	head = ft_stack_prepend(head, stack2);
	TEST_ASSERT_TRUE_MESSAGE(head->next == stack, "#1");
	TEST_ASSERT_TRUE_MESSAGE(head->next->next == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(head->next->prev == stack2, "#3");
	// NULL <- stack3 <-> stack2 <-> stack -> NULL
	head = ft_stack_prepend(head, stack3);
	TEST_ASSERT_TRUE_MESSAGE(head->next == stack2, "#1");
	TEST_ASSERT_TRUE_MESSAGE(head->next->next == stack, "#2");
	TEST_ASSERT_TRUE_MESSAGE(head->next->next->prev == stack2, "#3");
}

void test_ft_stack_del_top_0(void)
{
	t_stack	*stack;
	t_stack	*stack2;
	t_stack	*stack3;
	t_stack *head;

	stack = ft_stack(1);
	stack2 = ft_stack(2);
	stack3 = ft_stack(3);
	head = stack;

	ft_stack_append(head, stack2);
	ft_stack_append(head, stack3);
	// NULL <- stack <-> stack2 <-> stack3 -> NULL

	head = ft_stack_del_top(head);
	// NULL <- stack2 <-> stack3 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(head->next == stack3, "#1");
	TEST_ASSERT_TRUE_MESSAGE(head->prev == NULL, "#2");
	head = ft_stack_del_top(head);
	// NULL <- stack3 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(head->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(head->prev == NULL, "#4");
}

// delete top
// swap top bottom
// swap top 2
int test_stack(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_stack_0);
	RUN_TEST(test_ft_stack_append_0);
	RUN_TEST(test_ft_stack_prepend_0);
	RUN_TEST(test_ft_stack_del_top_0);
	return UNITY_END();
}
