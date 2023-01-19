/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:52 by tspoof            #+#    #+#             */
/*   Updated: 2023/01/19 17:20:52 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h> // remove this

// TODO:
// Check unique

static void	free_split(char **split)
{
	char	**indirect;

	indirect = split;
	while (*indirect)
	{
		free(*indirect);
		indirect++;
	}
	free(split);
}

static int	order_to_stack(t_vec *vec, t_vec *stack_a)
{
	int	i;
	char *args_indirect;

	args_indirect = vec->memory;

	i = 0;
	while (*args_indirect)
	{

		args_indirect++;
	}

	// args[y] != arg[x]
	// if args[y] > arg[x]
	// 		pos++;
}

static int	args_to_vec(char **args, t_vec *vec)
{
	int	num;

	while (*args)
	{
		num = ft_atoi(*args);
		if (vec_push(vec, &num) < 0)
			return (-1);
		args++;
	}
	return (1);
}

static int	get_args(t_vec stack_a, int argc, char *argv[])
{
	int		i;
	char	**args_str;
	t_vec	args;
	(void)stack_a;

	if (vec_new(&args, 1, 4) < 0)
		return (1);
	i = 1;
	while (i < argc)
	{
		args_str = ft_split(argv[i], ' ');
		if (!args_str)
			return (-1);
		if (args_to_vec(args_str, &args) < 0)
			return (-1);
		free_split(args_str);
		args_str = NULL;
		i++;
	}
	vec_free(&args);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vec	stack_a;
	// t_vec	stack_b;

	if (vec_new(&stack_a, 10, 4) < 0)
		return (1);
	if (argc == 1)
		return (0);
	if (get_args(stack_a, argc, argv) < 0)
		return (1);

	printf("jee");
	vec_free(&stack_a);
	return (0);
}
