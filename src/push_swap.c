/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:52 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/07 18:30:51 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h> // remove this

// swap
	// swap_top()

// push
	// stack2 = stack_prepend(stack2, stack1)
	// stack1 = stack_del_top(stack1)

// rotate
	// stack1 = stack_rotate(stack1)

// reverse_rotate
	// stack1 = stack_reverse_rotate(stack1)

int	main(int argc, char *argv[])
{
	t_vec	stack_a;
	// t_vec	stack_b;

	if (vec_new(&stack_a, 10, 4) < 0)
		return (1);
	if (argc == 1)
		return (0);
	if (get_args(&stack_a, argc, argv) < 0)
		return (1);

	printf("jee");
	vec_free(&stack_a);
	return (0);
}
