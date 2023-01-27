/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:21:23 by tspoof            #+#    #+#             */
/*   Updated: 2023/01/26 17:46:30 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// ft_btree_insert

// ft_btree_destroy

// ft_btree_search

t_btree	*ft_btree(void *content)
{
	t_btree	*btree;

	btree = (t_btree *)malloc(sizeof(t_btree));
	if (!btree)
		return (NULL);
	btree->content = content;
	btree->next = NULL;
	btree->prev = NULL;
	return (btree);
}
