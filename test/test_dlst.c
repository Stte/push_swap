#include "unity/unity.h"
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_ft_dlstnew_0(void)
{
	t_dlist *dlst;
	int	num;

	num = 1;
	dlst = ft_dlstnew(&num);
	TEST_ASSERT_TRUE_MESSAGE(dlst != NULL, "#1");
	TEST_ASSERT_TRUE_MESSAGE(dlst->next == NULL, "#2");
	TEST_ASSERT_TRUE_MESSAGE(dlst->prev == NULL, "#3");

}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_dlstnew_0);
	return UNITY_END();
}
