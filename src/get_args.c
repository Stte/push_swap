/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:36:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/08 19:31:07 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	free_split(char ***split)
{
	char	**indirect;

	indirect = *split;
	while (*indirect)
	{
		free(*indirect);
		indirect++;
	}
	free(*split);
}

static size_t	get_position(int *args, size_t args_len, int arg)
{
	size_t	i;
	size_t	position;

	i = 0;
	position = 0;
	while (i < args_len)
	{
		if (arg > args[i])
			position++;
		i++;
	}
	return (position);
}

static int	position_to_list(t_vec *vec, t_vec *stack_a)
{
	size_t	i;
	size_t	position;
	int	*args;

	args = (int *)(vec->memory);
	i = 0;
	while (i < vec->len)
	{
		position = get_position(args, vec->len, args[i]);

		// change this to use double linklists
		if (vec_push(stack_a, &position) < 0)
			return (-1);
		i++;
	}
	return (1);
}

static int	args_to_vec(char **args, t_vec *vec)
{
	int	num;

	if (!*args || !vec)
		return (-1);
	while (*args)
	{
		if (!is_valid_num(*args))
			return (-1);
		num = ft_atoi(*args);
		if (!is_unique_num(vec, num))
			return (-1);
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
	t_vec	args_vec;

	if (vec_new(&args_vec, 1, 4) < 0)
		return (-1);
	i = 1;
	while (i < argc)
	{
		args_str = ft_split(argv[i], ' ');
		if (!args_str)
			return (-1);
		if (args_to_vec(args_str, &args_vec) < 0)
			return (-1);
		free_split(&args_str);
		args_str = NULL;
		i++;
	}
	if (position_to_list(&args_vec, stack_a) < 0)
		return (-1);
	vec_free(&args_vec);
	return (1);
}
