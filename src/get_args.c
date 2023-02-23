/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:36:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/23 18:58:08 by tspoof           ###   ########.fr       */
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
	t_uint	position;

	position = 1;
	while (stack != NULL)
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
	int		num;
	t_stack	*node;

	if (!*args || !stack)
		return (-1);
	while (*args)
	{
		num = ft_atoi(*args);
		if (is_valid_num(num, *args) < 0)
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		if (!is_unique_num(*stack, num))
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		node = ft_stack(num);
		if (node)
			ft_stack_append(stack, &node);
		args++;
	}
	return (1);
}

// Turns arguments into positions.
// eg. [4, -5, 100, 7, 10] will be saved as [2, 1, 5, 3, 4]
int	get_args(t_stack **stack_a, int argc, char *argv[])
{
	int		i;
	char	**args_str;
	int		result;

	i = 1;
	while (i < argc)
	{
		args_str = ft_split(argv[i], ' ');
		if (!args_str)
			return (-1);
		result = args_to_stack(args_str, stack_a);
		free_split(&args_str);
		args_str = NULL;
		if (result < 0)
			return (-1);
		i++;
	}
	content_to_positional(*stack_a);
	return (1);
}
