/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:57:28 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/15 20:42:44 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(void (*f)(t_stack **, t_stack **), t_stack **dest,
		t_stack **source, char *command)
{
	f(dest, source);
	ft_putendl_fd(command, 1);
}

void	do_psr(void (*f)(t_stack **), t_stack **stack, char *command)
{
	f(stack);
	ft_putendl_fd(command, 1);
}

void	do_psr_both_stacks(void (*f)(t_stack *), t_stack *stack_a,
		t_stack *stack_b, char *command)
{
	f(stack_a);
	f(stack_b);
	ft_putendl_fd(command, 1);
}
