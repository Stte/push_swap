/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:52 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/21 18:34:00 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Loop thorough the stack_a, check the bit position and if it's 0 move it to stack_b
// Then move all the nodes thats next bit position is 1 back to stack_a


void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack			*indirect;
	unsigned int	i;
	unsigned int	bit_pos;
	unsigned int	stack_len;


	bit_pos = 1;
	while (bit_pos)
	{
		// check stack_a and push to stack_b
		indirect = *stack_a;
		i = 0;
		stack_len = ft_stack_len(*stack_a);
		while (i < stack_len)
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
			i++;
			// indirect = indirect->next;
		}
		bit_pos = bit_pos << 1;
		// check stack_b and push to stack_a
		indirect = *stack_b;
		while (indirect)
		{
			indirect = indirect->next;
			do_push(ft_stack_push, stack_a, stack_b, "pa");
			// if (bit_pos && indirect->pos & bit_pos)
			// {
			// 	indirect = indirect->next;
			// 	do_push(ft_stack_push, stack_a, stack_b, "pa");
			// }
			// else
			// 	indirect = indirect->next;
		}
		if (ft_stack_is_shorted(*stack_a) && ft_stack_len(*stack_b) == 0)
			break ;
	}
}
