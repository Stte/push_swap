/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:25 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/14 21:17:19 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// 3 2 1 -swap-> 2 3 1 -revers rotate-> 1 2 3
// 3 1 2 -rotate-> 1 2 3
// 2 3 1 -reverse rotate-> 1 2 3
// 2 1 3 -swap-> 1 2 3
// 1 3 2 -swap-> 3 1 2 -rotate-> 1 2 3
void	push_swap_three(t_stack **stack_a, t_vec *operations)
{
	t_stack	*next;
	t_stack	*next_after;

	next = (*stack_a)->next;
	next_after = (*stack_a)->next->next;
	if ((*stack_a)->pos == 2 && next->pos == 1 && next_after->pos == 0)
	{
		ft_stack_swap(stack_a);
		// command_to_vec(operations, "sa");
		ft_stack_reverse_rotate(stack_a);
		// command_to_vec(operations, "rra");
	}
	if ((*stack_a)->pos == 2 && next->pos == 0 && next_after->pos == 1)
	{
		ft_stack_rotate(stack_a);
		// command_to_vec(operations, "ra");
	}
	if ((*stack_a)->pos == 1 && next->pos == 2 && next_after->pos == 0)
	{
		ft_stack_reverse_rotate(stack_a);
		// command_to_vec(operations, "rra");
	}
	if ((*stack_a)->pos == 1 && next->pos == 0 && next_after->pos == 2)
	{
		ft_stack_swap(stack_a);
		// command_to_vec(operations, "sa");
	}
	if ((*stack_a)->pos == 0 && next->pos == 2 && next_after->pos == 1)
	{
		ft_stack_swap(stack_a);
		// command_to_vec(operations, "sa");
		ft_stack_rotate(stack_a);
		// command_to_vec(operations, "ra");
	}
}

void	push_swap_five(t_stack **stack_a, t_stack **stack_b)
{
	(void) stack_a;
	(void) stack_b;
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	(void) stack_a;
	(void) stack_b;
}
