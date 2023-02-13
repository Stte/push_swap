/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:20:02 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/09 14:23:58 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_stack_rotate(t_stack **head)
{
	t_stack *tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = *head;
	(*head)->next->prev = NULL;
	while ((*head)->next != NULL)
		*head = (*head)->next;
	(*head)->next = tmp;
	tmp->prev = *head;
	*head = tmp->next;
	tmp->next = NULL;
}

void	ft_stack_reverse_rotate(t_stack **head)
{
	t_stack	*indirect;

	if (!head || !*head || !(*head)->next)
		return ;
	indirect = *head;
	while (indirect->next != NULL)
		indirect = indirect->next;
	indirect->prev->next = NULL;
	indirect->next = *head;
	indirect->prev = NULL;
	(*head)->prev = indirect;
	*head = indirect;
}
