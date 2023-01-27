/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:27:34 by tspoof            #+#    #+#             */
/*   Updated: 2023/01/26 17:47:52 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_btree
{
	void			*content;
	struct s_btree	*next;
	struct s_btree	*prev;
}					t_btree;

int	get_args(t_vec *stack_a, int argc, char *argv[]);
int	is_unique_num(t_vec *vec, int num);
int	is_valid_num(char *str);

t_btree	*ft_btree(void *content);

#endif
