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
	TEST_ASSERT_TRUE_MESSAGE(node1->pos == 0, "#5");

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
	ft_stack_append(&node1, &node2);
	TEST_ASSERT_TRUE_MESSAGE(node1->next == node2, "#1");
	TEST_ASSERT_TRUE_MESSAGE(node1->next->next == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(node1->next->prev == node1, "#3");
	// NULL <- node1 <-> node2 <-> node3 -> NULL
	ft_stack_append(&node1, &node3);
	TEST_ASSERT_TRUE_MESSAGE(node1->next == node2, "#1");
	TEST_ASSERT_TRUE_MESSAGE(node1->next->next == node3, "#2");
	TEST_ASSERT_TRUE_MESSAGE(node1->next->next->prev == node2, "#3");

	free_stack(node1);
}

void test_ft_stack_append_1(void)
{
	t_stack	*stackA;
	t_stack	*node1;

	node1 = ft_stack(1);
	stackA = NULL;

	// NULL <- node1 -> NULL
	ft_stack_append(&stackA, &node1);
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == NULL, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA == node1, "#3");

	free_stack(stackA);
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

	ft_stack_append(&stackA, &node2);
	ft_stack_append(&stackA, &node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL
	// NULL

	ft_stack_push(&stackB, &stackA);
	// NULL <- node2 <-> node3 -> NULL
	// NULL <- node1 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA == node2, "#0");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node3, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node2, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackB->prev == NULL, "#6");
	TEST_ASSERT_TRUE_MESSAGE(stackB == node1, "#7");
	ft_stack_push(&stackA, &stackB);
	// NULL <- node1 <-> node2 <-> node3 -> NULL
	// NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node2, "#8");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#9");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == node3, "#10");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node1, "#11");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->next == NULL, "#12");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->prev == node2, "#13");
	TEST_ASSERT_TRUE_MESSAGE(stackA == node1, "#14");
	TEST_ASSERT_TRUE_MESSAGE(stackB == NULL, "#15");

	free_stack(stackA);
}

void test_ft_stack_push_1(void)
{
	t_stack *stackA;
	t_stack *stackB;

	stackA = NULL;
	stackB = NULL;

	ft_stack_push(&stackB, &stackA);
	TEST_ASSERT_TRUE_MESSAGE(stackA == NULL, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackB == NULL, "#2");
}

void test_ft_stack_push_2(void)
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

	ft_stack_append(&stackA, &node2);
	ft_stack_append(&stackA, &node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL
	// NULL

	ft_stack_push(&stackB, &stackA);
	// NULL <- node2 <-> node3 -> NULL
	// NULL <- node1 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA == node2, "#0");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node3, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node2, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackB->prev == NULL, "#6");
	TEST_ASSERT_TRUE_MESSAGE(stackB == node1, "#7");
	ft_stack_push(&stackB, &stackA);
	// NULL <- node3 -> NULL
	// NULL <- node2 <-> node1 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA == node3, "#7");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == NULL, "#8");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#9");
	TEST_ASSERT_TRUE_MESSAGE(stackB == node2, "#10");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next == node1, "#11");
	TEST_ASSERT_TRUE_MESSAGE(stackB->prev == NULL, "#12");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->next == NULL, "#13");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->prev == node2, "#14");
	ft_stack_push(&stackB, &stackA);
	// NULL
	// NULL <- node3 <-> node2 <-> node1 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA == NULL, "#15");
	TEST_ASSERT_TRUE_MESSAGE(stackB == node3, "#16");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next == node2, "#17");
	TEST_ASSERT_TRUE_MESSAGE(stackB->prev == NULL, "#18");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->next == node1, "#19");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->prev == node3, "#20");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->next->next == NULL, "#21");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->next->prev == node2, "#22");
	ft_stack_push(&stackB, &stackA);
	// NULL
	// NULL <- node3 <-> node2 <-> node1 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA == NULL, "#23");
	TEST_ASSERT_TRUE_MESSAGE(stackB == node3, "#24");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next == node2, "#25");
	TEST_ASSERT_TRUE_MESSAGE(stackB->prev == NULL, "#26");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->next == node1, "#27");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->prev == node3, "#28");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->next->next == NULL, "#29");
	TEST_ASSERT_TRUE_MESSAGE(stackB->next->next->prev == node2, "#30");

	free_stack(stackB);
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

	ft_stack_append(&stackA, &node2);
	ft_stack_append(&stackA, &node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL

	ft_stack_swap(&stackA);
	// NULL <- node2 <-> node1 <-> node3 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node1, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == node3, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node2, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->prev == node1, "#6");

	free_stack(stackA);
}

void test_ft_stack_swap_1(void)
{
	t_stack	*node1;
	t_stack *stackA;

	node1 = ft_stack(1);
	stackA = node1;

	ft_stack_swap(&stackA);
	TEST_ASSERT_TRUE_MESSAGE(stackA == node1, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#3");

	free_stack(stackA);
}

void test_ft_stack_swap_2(void)
{
	t_stack *stackA;

	stackA = NULL;

	ft_stack_swap(&stackA);
	TEST_ASSERT_TRUE_MESSAGE(stackA == NULL, "#1");
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

	ft_stack_append(&stackA, &node2);
	ft_stack_append(&stackA, &node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL

	ft_stack_rotate(&stackA);
	// NULL <- node2 <-> node3 <-> node1 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node3, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == node1, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node2, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->prev == node3, "#6");

	free_stack(stackA);
}

void test_ft_stack_rotate_1(void)
{
	t_stack *stackA;

	stackA = NULL;
	ft_stack_rotate(&stackA);
	TEST_ASSERT_TRUE_MESSAGE(stackA == NULL, "#1");
}

void test_ft_stack_rotate_2(void)
{
	t_stack *stackA;
	t_stack *node1;

	node1 = ft_stack(1);
	stackA = node1;
	ft_stack_rotate(&stackA);
	TEST_ASSERT_TRUE_MESSAGE(stackA == node1, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == NULL, "#3");
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

	ft_stack_append(&stackA, &node2);
	ft_stack_append(&stackA, &node3);
	// NULL <- node1 <-> node2 <-> node3 -> NULL

	ft_stack_reverse_rotate(&stackA);
	// NULL <- node3 <-> node1 <-> node2 -> NULL
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == node1, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next == node2, "#3");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->prev == node3, "#4");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->next == NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next->next->prev == node1, "#6");

	free_stack(stackA);
}

void test_ft_stack_reverse_rotate_1(void)
{
	t_stack *stackA;

	stackA = NULL;
	ft_stack_reverse_rotate(&stackA);
	TEST_ASSERT_TRUE_MESSAGE(stackA == NULL, "#1");
}

void test_ft_stack_reverse_rotate_2(void)
{
	t_stack *stackA;
	t_stack *node1;

	node1 = ft_stack(1);
	stackA = node1;
	ft_stack_reverse_rotate(&stackA);
	TEST_ASSERT_TRUE_MESSAGE(stackA == node1, "#1");
	TEST_ASSERT_TRUE_MESSAGE(stackA->prev == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(stackA->next == NULL, "#3");
}

void test_ft_stack_len_0(void)
{
	t_stack	*stackA;
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = ft_stack(1);
	node2 = ft_stack(2);
	node3 = ft_stack(3);
	stackA = NULL;

	TEST_ASSERT_TRUE_MESSAGE(ft_stack_len(stackA) == 0, "#1");
	ft_stack_append(&stackA, &node1);
	TEST_ASSERT_TRUE_MESSAGE(ft_stack_len(stackA) == 1, "#2");
	ft_stack_append(&stackA, &node2);
	TEST_ASSERT_TRUE_MESSAGE(ft_stack_len(stackA) == 2, "#3");
	ft_stack_append(&stackA, &node3);
	TEST_ASSERT_TRUE_MESSAGE(ft_stack_len(stackA) == 3, "#4");
}

int test_stack(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_stack_0);
	RUN_TEST(test_ft_stack_append_0);
	RUN_TEST(test_ft_stack_append_1);
	RUN_TEST(test_ft_stack_push_0);
	RUN_TEST(test_ft_stack_push_1);
	RUN_TEST(test_ft_stack_push_2);
	RUN_TEST(test_ft_stack_swap_0);
	RUN_TEST(test_ft_stack_swap_1);
	RUN_TEST(test_ft_stack_swap_2);
	RUN_TEST(test_ft_stack_rotate_0);
	RUN_TEST(test_ft_stack_rotate_1);
	RUN_TEST(test_ft_stack_rotate_2);
	RUN_TEST(test_ft_stack_reverse_rotate_0);
	RUN_TEST(test_ft_stack_reverse_rotate_1);
	RUN_TEST(test_ft_stack_reverse_rotate_2);
	RUN_TEST(test_ft_stack_len_0);
	return UNITY_END();
}
