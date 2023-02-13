#include "test.h"

void setUp(void) {
}

void tearDown(void) {
}

int main(void)
{
	test_stack();
	test_validity();
	test_get_args();
	test_push_swap_three();
	return (0);
}
