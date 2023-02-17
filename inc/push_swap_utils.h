/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:07:51 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/17 15:10:59 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "push_swap.h"

int				is_smallest(unsigned int pos, t_stack *stack);
unsigned int	smallest_pos(t_stack *stack);
int				top_closer(unsigned int pos, t_stack *stack_a);

#endif
