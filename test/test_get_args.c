#include "unity/unity.h"
#include "push_swap.h"
#include "libft.h"

void setUp(void) {
}

void tearDown(void) {
}

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


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_args_0);
	return UNITY_END();
}
