/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:52 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/22 15:55:51 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Loop thorough the stack_a, check the bit position and if it's 0 move it to stack_b
static void	stack_a_handler(t_stack **stack_a, t_stack **stack_b, uint bit_pos)
{
	t_stack	*indirect;
	uint	stack_len;

	indirect = *stack_a;
	stack_len = ft_stack_len(*stack_a);
	while (stack_len > 0)
	{
		if (indirect->pos & bit_pos)
		{
			indirect = indirect->next;
			do_psr(ft_stack_rotate, stack_a, "ra");
		}
		else
		{
			indirect = indirect->next;
			do_push(ft_stack_push, stack_b, stack_a, "pb");
		}
		stack_len--;
	}
}

// Loop thorough the stack_b, check the bit position and if it's 1 move it to stack_a
static void	stack_b_handler(t_stack **stack_a, t_stack **stack_b, uint bit_pos)
{
	t_stack	*indirect;
	uint	stack_len;

	indirect = *stack_b;
	stack_len = ft_stack_len(*stack_b);
	while (stack_len > 0)
	{
		// indirect = indirect->next;
		// do_push(ft_stack_push, stack_a, stack_b, "pa");
		if (indirect->pos & bit_pos)
		{
			indirect = indirect->next;
			do_push(ft_stack_push, stack_a, stack_b, "pa");
		}
		else
		{
			indirect = indirect->next;
			do_psr(ft_stack_rotate, stack_b, "rb");
		}
		stack_len--;
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	uint	bit_pos;

	bit_pos = 1;
	while (!ft_stack_is_shorted(*stack_a) && !ft_stack_is_rev_shorted(*stack_a))
	{
		stack_a_handler(stack_a, stack_b, bit_pos);
		bit_pos <<= 1;
		stack_b_handler(stack_a, stack_b, bit_pos);
	}
	while (ft_stack_len(*stack_b))
	{
		do_push(ft_stack_push, stack_a, stack_b, "pa");
	}
}


// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
