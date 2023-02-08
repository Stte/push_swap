/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:24:35 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/08 18:22:16 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_stack_push(t_stack **dest, t_stack **source)
{
	t_stack	*src_next;

	if (!source || !*source)
		return ;
	src_next = (*source)->next;
	if (!dest || !*dest)
	{
		*dest = *source;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = *source;
		(*source)->next = *dest;
		*dest = *source;
	}
	(*dest)->prev = NULL;
	*source = src_next;
	if (*source)
		(*source)->prev = NULL;
}
