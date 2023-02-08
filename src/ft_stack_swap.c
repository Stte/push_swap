/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:22:16 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/08 18:21:51 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_stack_swap(t_stack *head)
{
	head->prev = head->next;
	head->next = head->prev->next;
	head->next->prev = head;
	head = head->prev;
	head->next = head->prev;
	head->prev = NULL;
	return (head);
}
