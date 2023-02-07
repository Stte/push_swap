/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:27:34 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/07 18:18:45 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int		get_args(t_vec *stack_a, int argc, char *argv[]);
int		is_unique_num(t_vec *vec, int num);
int		is_valid_num(char *str);

/**
 * @brief Create doubly linked node
 *
 * @param content
 * @return t_stack*
 */
t_stack	*ft_stack(int content);
/**
 * @brief Add node to end of the list
 *
 * @param head
 * @param node
 */
void	ft_stack_append(t_stack *head, t_stack *node);
/**
 * @brief Add node to the start of the list
 *
 * @param head
 * @param node
 * @return t_stack*
 */
t_stack	*ft_stack_prepend(t_stack *head, t_stack *node);
/**
 * @brief Remove the first node
 *
 * @param head
 * @return t_stack*
 */
t_stack	*ft_stack_del_top(t_stack *head);
/**
 * @brief Swap the first 2 nodes at the top of the stack.
 *
 * @note Null <- node2 <-> node1 <-> node3 -> NULL
 *
 * @param head Head of the stack
 * @return t_stack* New head of the stack
 */
t_stack	*ft_stack_swap_top(t_stack *head);
/**
 * @brief Shift up all nodes of stack by 1.
 *
 * The first element becomes the last one.
 * @note NULL <-node2 <-> node3 <-> node1 -> NULL
 *
 * @param head
 * @return t_stack*
 */
t_stack	*ft_stack_rotate(t_stack *head);
/**
 * @brief Shift down all elements of stack by 1.
 *
 * The last element becomes the first one.
 * @note NULL <- node3 <-> node1 <-> node2 -> NULL
 *
 * @param head
 * @return t_stack*
 */
t_stack	*ft_stack_reverse_rotate(t_stack *head);

#endif
