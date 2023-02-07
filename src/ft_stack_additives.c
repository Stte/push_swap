/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_additives.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:24:35 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/07 18:24:44 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
