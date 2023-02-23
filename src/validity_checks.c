/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:04:46 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/23 18:59:48 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_unique_num(t_stack *stack, int num)
{
	if (!stack)
		return (1);
	while (stack != NULL)
	{
		if (stack->content == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	is_only_digits(char *str)
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

int	is_valid_num(int num, char *str)
{
	char	*check;
	t_uint	str_len;

	if (is_only_digits(str) < 0)
		return (-1);
	check = ft_itoa(num);
	if (!check)
		return (0);
	str_len = ft_strlen(str);
	if (str_len != ft_strlen(check))
	{
		free(check);
		return (-1);
	}
	if (ft_strncmp(check, str, str_len) != 0)
	{
		free(check);
		return (-1);
	}
	free(check);
	return (1);
}
