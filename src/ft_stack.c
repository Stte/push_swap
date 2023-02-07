/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:21:23 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/07 14:27:23 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_stack_swap_top(t_stack *head)
{
	// t_stack	*tmp;

	// tmp = head;
	head->prev = head->next;
	head->next = head->prev->next;
	head->next->prev = head;
	head = head->prev;
	head->next = head->prev;
	head->prev = NULL;
	return (head);
}

t_stack	*ft_stack_del_top(t_stack *head)
{
	head = head->next;
	head->prev = NULL;
	return (head);
}

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
