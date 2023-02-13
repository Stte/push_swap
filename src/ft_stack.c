/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:21:23 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/13 11:50:19 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}
