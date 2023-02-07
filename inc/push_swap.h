/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:27:34 by tspoof            #+#    #+#             */
/*   Updated: 2023/02/06 17:43:41 by tspoof           ###   ########.fr       */
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

t_stack	*ft_stack(int content);
void	ft_stack_append(t_stack *head, t_stack *node);
t_stack	*ft_stack_prepend(t_stack *head, t_stack *node);

#endif
