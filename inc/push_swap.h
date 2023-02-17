/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:27:34 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/17 16:25:58 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				content;
	unsigned int	pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int		get_args(t_stack **stack_a, int argc, char *argv[]);
int		is_unique_num(t_stack *vec, int num);
int		is_valid_num(char *str);
void	push_swap_three(t_stack **stack_a);
void	push_swap_five(t_stack **stack_a, t_stack **stack_b);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	do_psr(void (*f)(t_stack **), t_stack **stack, char *command);
void	do_psr_both_stacks(void (*f)(t_stack *), t_stack *stack_a,
			t_stack *stack_b, char *command);
void	do_push(void (*f)(t_stack **, t_stack **), t_stack **dest,
			t_stack **source, char *command);

/**
 * @brief Create a doubly linked node
 *
 * @param content
 * @return t_stack*
 */
t_stack	*ft_stack(int content);
/**
 * @brief Add a node to the end of the list
 *
 * @param head
 * @param node
 */
void	ft_stack_append(t_stack **head, t_stack **node);
/**
 * @brief Push the first element between the stacks
 *
 * @param dest
 * @param source
 */
void	ft_stack_push(t_stack **dest, t_stack **source);
/**
 * @brief Swap the first 2 nodes at the top of the stack.
 *
 * @note Null <- node2 <-> node1 <-> node3 -> NULL
 *
 * @param head Head of the stack
 */
void	ft_stack_swap(t_stack **head);
/**
 * @brief Shift up all nodes of stack by 1.
 *
 * The first element becomes the last one.
 * @note NULL <-node2 <-> node3 <-> node1 -> NULL
 *
 * @param head
 */
void	ft_stack_rotate(t_stack **head);
/**
 * @brief Shift down all elements of stack by 1.
 *
 * The last element becomes the first one.
 * @note NULL <- node3 <-> node1 <-> node2 -> NULL
 *
 * @param head
 */
void	ft_stack_reverse_rotate(t_stack **head);
/**
 * @brief Counts number of nodes.
 *
 * @return size_t
 */
size_t	ft_stack_len(t_stack *head);
void	ft_stack_free(t_stack *head);
int		ft_stack_is_shorted(t_stack *stack);

#endif
