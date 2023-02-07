/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:21:23 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/06 17:48:58 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_stack_prepend(t_stack *head, t_stack *node)
{
	head->prev = node;
	node->next = head;
	return (node);
}

void	ft_stack_append(t_stack *head, t_stack *node)
{
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	node->prev = head;
}

t_stack	*ft_stack(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}
