/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:22:16 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/09 14:18:50 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_stack_swap(t_stack **head)
{
	if (!head || !*head || !(*head)->next)
		return ;
	(*head)->prev = (*head)->next;
	(*head)->next = (*head)->prev->next;
	(*head)->next->prev = *head;
	*head = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
