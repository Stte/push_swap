/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:52 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/13 14:25:32 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h> // remove this

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	// t_stack	*stack_b;

	stack_a = NULL;
	// stack_b = NULL;
	if (argc == 1)
		return (0);
	if (get_args(&stack_a, argc, argv) < 0)
		return (1);
	return (0);
}
