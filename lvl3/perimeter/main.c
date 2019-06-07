/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:32:19 by tholzheu          #+#    #+#             */
/*   Updated: 2019/06/07 14:38:21 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
}				t_node;

void perimeter(struct s_node *root);

t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->value = value;
	new->right = NULL;
	new->left = NULL;
	return (new);
}


int		main(void)
{
	t_node	*root;

	root = new_node(5);
	root->right = new_node(6);
	root->right->left = new_node(70);
	root->left = new_node(10);
	root->left->left = new_node(8);
	root->left->right = new_node(7);
	perimeter(root);
	return (1);
}
