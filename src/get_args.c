/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:36:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/01/20 20:43:51 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

static int	position_to_stack(t_vec *vec, t_vec *stack_a)
{
	size_t	i;
	size_t	j;
	int	position;
	int	*args;
	int	*args_indirect;

	args = (int *)(vec->memory);
	args_indirect = args;
	i = 0;
	while (i < vec->len)
	{
		j = 0;
		position = 0;
		while (j < vec->len)
		{
			if (*args_indirect > args[j])
				position++;
			j++;
		}
		if (vec_push(stack_a, &position) < 0)
			return (-1);
		args_indirect++;
		i++;
	}
	return (1);
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

// Turns arguments into position vector based on the size of the number.
// eg. [4, -5, 100, 7, 10] will be saved as [1, 0, 4, 2, 3]

int	get_args(t_vec *stack_a, int argc, char *argv[])
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
	if (position_to_stack(&args, stack_a) < 0)
		return (-1);
	vec_free(&args);
	return (1);
}
