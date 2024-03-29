/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:53:37 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/23 19:11:17 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_largest(int value, int val2, int val3)
{
	if (value > val2 && value > val3)
		return (1);
	return (0);
}

void	push_swap_three(t_stack **stack_a)
{
	t_stack	*next;
	t_stack	*next_after;

	next = (*stack_a)->next;
	next_after = (*stack_a)->next->next;
	if (!is_largest(next_after->pos, (*stack_a)->pos, next->pos))
	{
		if (is_largest((*stack_a)->pos, next->pos, next_after->pos))
			do_psr(ft_stack_rotate, stack_a, "ra");
		else
			do_psr(ft_stack_reverse_rotate, stack_a, "rra");
	}
	next = (*stack_a)->next;
	next_after = (*stack_a)->next->next;
	if (!is_smallest((*stack_a)->pos, *stack_a))
		do_psr(ft_stack_swap, stack_a, "sa");
}
