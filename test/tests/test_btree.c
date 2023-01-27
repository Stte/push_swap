#include "unity.h"
#include "push_swap.h"
#include "libft.h"

void test_ft_btree_0(void)
{
	t_btree *btree;
	int	num;

	num = 42;
	btree = ft_btree(&num);
	TEST_ASSERT_TRUE_MESSAGE(btree != NULL, "#1");
	TEST_ASSERT_TRUE_MESSAGE(*(int *)(btree->content) == 42, "#2");
	TEST_ASSERT_TRUE_MESSAGE(btree->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(btree->prev == NULL, "#4");
}

void test_ft_btree_1(void)
{
	t_btree	*btree;
	char	*str = "Test";

	btree = ft_btree(str);
	TEST_ASSERT_TRUE_MESSAGE(btree != NULL, "#1");
	TEST_ASSERT_TRUE_MESSAGE(*(int *)(btree->content) == 42, "#2");
	TEST_ASSERT_TRUE_MESSAGE(btree->next == NULL, "#3");
	TEST_ASSERT_TRUE_MESSAGE(btree->prev == NULL, "#4");
}


int test_btree(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_btree_0);
	return UNITY_END();
}
