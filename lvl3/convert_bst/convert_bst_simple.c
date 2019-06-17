/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 14:42:14 by tholzheu          #+#    #+#             */
/*   Updated: 2019/06/16 17:09:40 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
}		t_node;

void		fn(t_node *bst, t_node **head, t_node **last)
{
	if (!bst)
		return ;
	static t_node	*prev = NULL;

	fn(bst->left, head, last);
	if (prev == NULL)
		*head = bst;
	else
	{
		bst->left = prev;
		prev->right = bst;
	}
	prev = bst;
	*last = bst;
	fn(bst->right, head, last);
}

t_node		*convert_bst(t_node *bst)
{
	t_node	*head = NULL;
	t_node	*last = NULL;

	if (!bst)
		return (NULL);
	fn(bst, &head, &last);
	head->left = last;
	last->right = head;
	return (head);
}
