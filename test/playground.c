#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

int	main(void)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = ft_stack(1);
	node2 = ft_stack(2);
	node3 = ft_stack(3);

	// NULL <- node1 <-> node2 -> NULL
	ft_stack_append(&node1, &node2);
	// NULL <- node1 <-> node2 <-> node3 -> NULL
	ft_stack_append(&node1, &node3);

	return (0);
}
