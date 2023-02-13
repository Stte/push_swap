/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:36:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/13 16:50:05 by tspoof           ###   ########.fr       */
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
		*indirect = NULL;
		indirect++;
	}
	free(*split);
	*split = NULL;
}

static void	position(t_stack *node, t_stack *stack)
{
	unsigned int	position;

	position = 0;
	while (stack->next != NULL)
	{
		if (node->content > stack->content)
			position++;
		stack = stack->next;
	}
	node->pos = position;
}

static void	content_to_positional(t_stack *stack_a)
{
	t_stack	*node;

	node = stack_a;
	while (node != NULL)
	{
		position(node, stack_a);
		node = node->next;
	}
}

static int	args_to_stack(char **args, t_stack **stack)
{
	int	num;
	t_stack *node;

	if (!*args || !stack)
		return (-1);
	while (*args)
	{
		if (!is_valid_num(*args))
			return (-1);
		num = ft_atoi(*args);
		if (!is_unique_num(*stack, num))
			return (-1);
		node = ft_stack(num);
		if (node)
			ft_stack_append(stack, &node);
		args++;
	}
	return (1);
}

// Turns arguments into position vector based on the size of the number.
// eg. [4, -5, 100, 7, 10] will be saved as [1, 0, 4, 2, 3]

int	get_args(t_stack **stack_a, int argc, char *argv[])
{
	int		i;
	char	**args_str;

	i = 1;
	while (i < argc)
	{
		args_str = ft_split(argv[i], ' ');
		if (!args_str)
			return (-1);
		if (args_to_stack(args_str, stack_a) < 0)
			return (-1);
		free_split(&args_str);
		args_str = NULL;
		i++;
	}
	content_to_positional(*stack_a);
	return (1);
}
