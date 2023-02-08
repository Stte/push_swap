#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

int	main(void)
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
	ft_stack_push(&stackB, &stackA);
	ft_stack_push(&stackA, &stackB);

	return (0);
}
