/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:21:23 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/16 17:38:02 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ft_stack_is_shorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->pos > stack->next->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_stack_free(t_stack *head)
{
	t_stack	*next;

	if (!head)
		return ;
	while (head != NULL)
	{
		next = (head)->next;
		free(head);
		head = next;
	}
}

size_t	ft_stack_len(t_stack *head)
{
	size_t	len;

	if (!head)
		return (0);
	len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return (len);
}

void	ft_stack_append(t_stack **head, t_stack **node)
{
	t_stack	*indirect;

	if (!head)
		return ;
	if (!*head)
	{
		*head = *node;
		return ;
	}
	indirect = *head;
	while (indirect->next != NULL)
		indirect = indirect->next;
	indirect->next = *node;
	(*node)->prev = indirect;
}

t_stack	*ft_stack(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->pos = 0;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}
