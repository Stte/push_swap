/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:53:33 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/16 18:27:14 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_smallest(unsigned int pos, t_stack *stack)
{
	while (stack != NULL)
	{
		if (pos > stack->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static unsigned int	smallest_pos(t_stack *stack)
{
	unsigned int	min;

	min = 0;
	while (stack != NULL)
	{
		if (stack->pos < min)
			min = stack->pos;
		stack = stack->next;
	}
	return (min);
}

// Get the rotate direction.
// If distance to top is less than distance to bottom returns 1 else 0.
static int	top_closer(unsigned int pos, t_stack *stack_a)
{
	unsigned int	top;
	unsigned int	bottom;

	bottom = 0;
	while (stack_a != NULL)
	{
		if (stack_a->pos == pos)
		{
			top = bottom;
			bottom = 0;
		}
		bottom++;
		stack_a = stack_a->next;
	}
	bottom++;
	if (top < bottom)
		return (1);
	return (0);
}

// 2 3 5 1 4 -> 1 5 3 2 4 -> 5 3 2 4 ->
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
