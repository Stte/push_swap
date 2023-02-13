/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:04:46 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/09 17:13:46 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_unique_num(t_stack *stack, int num)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->content == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_valid_num(char *str)
{
	int	result;

	result = 0;
	if (!str || !*str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		result = 1;
		str++;
	}
	return (result);
}
