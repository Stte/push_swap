#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

int	main(void)
{
	t_btree	*test;
	t_vec	vec;
	int		arr[] = {1, 2, 3};

	vec_from(&vec, arr, 3, sizeof(int));

	test = ft_btree(vec.memory);

	int *i = test->content;

	if (i)
		;

	return (0);
}
