#include "unity.h"
#include "push_swap.h"
#include "libft.h"

void test_is_unique_num_0(void)
{
	t_vec	stack;
	int		nums[] = {1, 2, 3};

	TEST_ASSERT_EQUAL_INT_MESSAGE(1, vec_from(&stack, &nums, 3, 4), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, is_unique_num(&stack, 4), "#2");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, is_unique_num(&stack, -4), "#3");
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, is_unique_num(&stack, 2), "#4");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, is_unique_num(NULL, 2), "#5");
	vec_free(&stack);
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
