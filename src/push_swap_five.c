/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:53:33 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/21 14:39:39 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_five(t_stack **stack_a, t_stack **stack_b)
{
	while (1)
	{
		if (is_smallest((*stack_a)->pos, *stack_a) && ft_stack_len(*stack_a) > 3
			&& !ft_stack_is_shorted(*stack_a))
			do_push(ft_stack_push, stack_b, stack_a, "pb");
		else if (!ft_stack_is_shorted(*stack_a))
		{
			if (top_closer(smallest_pos(*stack_a), *stack_a))
				do_psr(ft_stack_rotate, stack_a, "ra");
			else
				do_psr(ft_stack_reverse_rotate, stack_a, "rra");
		}
		if (ft_stack_len(*stack_a) <= 3)
			push_swap_three(stack_a);
		if (ft_stack_is_shorted(*stack_a) && ft_stack_len(*stack_b) > 0)
			do_push(ft_stack_push, stack_a, stack_b, "pa");
		if (ft_stack_is_shorted(*stack_a) && ft_stack_len(*stack_b) == 0)
			break ;
	}
}
