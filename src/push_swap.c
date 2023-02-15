/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:52 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/15 19:50:42 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	stack_len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (get_args(&stack_a, argc, argv) < 0)
		return (1);
	stack_len = ft_stack_len(stack_a);
	if (stack_len == 3)
		push_swap_three(&stack_a);
	if (stack_len == 5)
		push_swap_five(&stack_a, &stack_b);
	else
		push_swap(&stack_a, &stack_b);
	ft_stack_free(stack_a);
	ft_stack_free(stack_b);
	return (0);
}
