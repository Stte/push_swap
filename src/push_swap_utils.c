/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:20:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/23 19:12:09 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smallest(t_uint pos, t_stack *stack)
{
	while (stack != NULL)
	{
		if (pos > stack->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_uint	smallest_pos(t_stack *stack)
{
	t_uint	min;

	min = stack->pos;
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
int	top_closer(t_uint pos, t_stack *stack_a)
{
	t_uint	top;
	t_uint	bottom;

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
