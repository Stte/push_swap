/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_shorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:44:01 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/23 18:52:00 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_stack_is_shorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->next->pos != stack->pos + 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_stack_is_rev_shorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->next->pos != stack->pos - 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}
