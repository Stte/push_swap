#include "unity.h"
#include "push_swap.h"
#include "libft.h"

void test_get_args_0(void)
{
	t_vec	stack;
	char	*argv[6];
	argv[0] = "test";
	argv[1] = "9";
	argv[2] = "2";
	argv[3] = "-3";
	argv[4] = "0";
	argv[5] = "100";
	int		expected[] = {3, 2, 0, 1, 4};
	int		*actual;

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, vec_new(&stack, 1, 4), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, get_args(&stack, 6, argv), "#2");
	actual = (int *)(stack.memory);
	TEST_ASSERT_EQUAL_MEMORY(expected, actual, 5*4);
	vec_free(&stack);
}

void test_get_args_1(void)
{
	t_vec	stack;
	char	*argv[6];
	argv[0] = "test";
	argv[1] = "9";
	argv[2] = "2";
	argv[3] = "2";
	argv[4] = "0";
	argv[5] = "100";

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, vec_new(&stack, 1, 4), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, get_args(&stack, 6, argv), "equal check");
	vec_free(&stack);
}

void test_get_args_2(void)
{
	t_vec	stack;
	char	*argv[2];
	argv[0] = "test";
	argv[1] = " ";

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, vec_new(&stack, 1, 4), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, get_args(&stack, 2, argv), "not a number");
	vec_free(&stack);
}
void test_get_args_3(void)
{
	t_vec	stack;
	char	*argv[2];
	argv[0] = "test";
	argv[1] = "a";

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, vec_new(&stack, 1, 4), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, get_args(&stack, 2, argv), "not a number");
	vec_free(&stack);
}
void test_get_args_4(void)
{
	t_vec	stack;
	char	*argv[2];
	argv[0] = "test";
	argv[1] = "\n";

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, vec_new(&stack, 1, 4), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, get_args(&stack, 2, argv), "not a number");
	vec_free(&stack);
}
void test_get_args_5(void)
{
	t_vec	stack;
	char	*argv[2];
	argv[0] = "test";
	argv[1] = "152fsd252";

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, vec_new(&stack, 1, 4), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, get_args(&stack, 2, argv), "not a number");
	vec_free(&stack);
}


int test_get_args(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_args_0);
	RUN_TEST(test_get_args_1);
	RUN_TEST(test_get_args_2);
	RUN_TEST(test_get_args_3);
	RUN_TEST(test_get_args_4);
	RUN_TEST(test_get_args_5);
	return UNITY_END();
}
