/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:20:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/17 15:07:23 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smallest(unsigned int pos, t_stack *stack)
{
	while (stack != NULL)
	{
		if (pos > stack->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}

unsigned int	smallest_pos(t_stack *stack)
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
int	top_closer(unsigned int pos, t_stack *stack_a)
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
