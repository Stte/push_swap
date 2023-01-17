/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:52 by tspoof            #+#    #+#             */
/*   Updated: 2023/01/17 16:36:13 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h> // remove this

// void	get_args(t_vec stack_a, char *argv[])
// {
// 	t_vec	arg;

// 	if (stack_a.memory)
// 		;

// 	if (vec_from(&arg, *argv))
// 	printf("%s", argv[1]);
// }

int	main(int argc, char *argv[])
{
	t_vec			stack_a;
	int	i;
	// t_vec	stack_b;

	if (vec_new(&stack_a, 10, 4) < 0)
		return (1);
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		vec_push(&stack_a, argv[i]);
		i++;
	}
	// get_args(stack_a, argv);

	return (0);
}
