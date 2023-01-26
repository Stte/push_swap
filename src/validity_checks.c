/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:04:46 by tspoof            #+#    #+#             */
/*   Updated: 2023/01/23 16:55:32 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_unique_num(t_vec *vec, int num)
{
	size_t	i;
	int		*ptr;

	if (!vec)
		return (-1);
	ptr = (int *)vec->memory;
	i = 0;
	while (i < vec->len)
	{
		if (num == ptr[i])
			return (0);
		i++;
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
