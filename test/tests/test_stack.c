#include "unity.h"
#include "push_swap.h"
#include "libft.h"

void free_stack(t_stack *stack)
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

void test_ft_stack_0(void)
{
	t_stack *node1;

	node1 = ft_stack(42);
	TEST_ASSERT_TRUE_MESSAGE(node1 != NULL, "#1");
	TEST_ASSERT_TRUE_MESSAGE(node1->content == 42, "#2");
	TEST_ASSERT_TRUE_MESSAGE(node1->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(node1->prev == NULL, "#4");

	free_stack(node1);
}

void test_ft_stack_append_0(void)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = ft_stack(1);
	node2 = ft_stack(2);
	node3 = ft_stack(3);

	// NULL <- node1 <-> node2 -> NULL
	ft_stack_append(node1, node2);
	TEST_ASSERT_TRUE_MESSAGE(node1->next == node2, "#1");
	TEST_ASSERT_TRUE_MESSAGE(node1->next->next == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(node1->next->prev == node1, "#3");
	// NULL <- node1 <-> node2 <-> node3 -> NULL
	ft_stack_append(node1, node3);
	TEST_ASSERT_TRUE_MESSAGE(node1->next == node2, "#1");
	TEST_ASSERT_TRUE_MESSAGE(node1->next->next == node3, "#2");
	TEST_ASSERT_TRUE_MESSAGE(node1->next->next->prev == node2, "#3");

	free_stack(node1);
}

void test_ft_stack_push_0(void)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;
	t_stack *stackA;
	t_stack *stackB;

	node1 = ft_stack(1);
	node2 = ft_stack(2);
	node3 = ft_stack(3);
	stackA = node1;
	stackB = NULL;

	ft_stack_append(stackA, node2);
	ft_stack_append(stackA, node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL
	// NULL

	ft_stack_push(&stackB, &stackA);
	// NULL <- node2 <-> node3 -> NULL
	// NULL <- node1 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node3, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node2, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackB->prev == NULL, "#6");
	ft_stack_push(&stackA, &stackB);
	// NULL <- node1 <-> node2 <-> node3 -> NULL
	// NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node2, "#7");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#8");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == node3, "#9");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node1, "#10");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->next == NULL, "#11");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->prev == node2, "#12");

	free_stack(stackA);
}

void test_ft_stack_swap_0(void)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;
	t_stack *stackA;

	node1 = ft_stack(1);
	node2 = ft_stack(2);
	node3 = ft_stack(3);
	stackA = node1;

	ft_stack_append(stackA, node2);
	ft_stack_append(stackA, node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL

	stackA = ft_stack_swap(stackA);
	// NULL <- node2 <-> node1 <-> node3 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node1, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == node3, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node2, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->prev == node1, "#6");

	free_stack(stackA);
}

void test_ft_stack_rotate_0(void)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;
	t_stack *stackA;

	node1 = ft_stack(1);
	node2 = ft_stack(2);
	node3 = ft_stack(3);
	stackA = node1;

	ft_stack_append(stackA, node2);
	ft_stack_append(stackA, node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL

	stackA = ft_stack_rotate(stackA);
	// NULL <- node2 <-> node3 <-> node1 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node3, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == node1, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node2, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->prev == node3, "#6");

	free_stack(stackA);
}

void test_ft_stack_reverse_rotate_0(void)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;
	t_stack *stackA;

	node1 = ft_stack(1);
	node2 = ft_stack(2);
	node3 = ft_stack(3);
	stackA = node1;

	ft_stack_append(stackA, node2);
	ft_stack_append(stackA, node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL

	stackA = ft_stack_reverse_rotate(stackA);
	// NULL <- node3 <-> node1 <-> node2 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node1, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == node2, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node3, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->prev == node1, "#6");

	free_stack(stackA);
}

int test_stack(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_stack_0);
	RUN_TEST(test_ft_stack_append_0);
	RUN_TEST(test_ft_stack_push_0);
	RUN_TEST(test_ft_stack_swap_0);
	RUN_TEST(test_ft_stack_rotate_0);
	RUN_TEST(test_ft_stack_reverse_rotate_0);
	return UNITY_END();
}
