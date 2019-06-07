/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:21:55 by tholzheu          #+#    #+#             */
/*   Updated: 2019/06/07 14:38:19 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
}				t_node;

void	leftmost(t_node *root) // pass the root->left
{
	if (!root)
		return ;
	if (root->left || root->right)
		printf(" %d", root->value);
	leftmost(root->left);
}

void	leafs(t_node *root)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
		printf(" %d", root->value);
	leafs(root->left);
	leafs(root->right);
}

void	rightmost(t_node *root) // pass the root->right
{
	if (!root)
		return ;
	rightmost(root->right);
	if (root->left || root->right)
		printf(" %d", root->value);
}

void	perimeter(t_node *root)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
	{
		printf("%d\n", root->value);
		return ;
	}
	printf("%d", root->value);
	leftmost(root->left);
	leafs(root);
	rightmost(root->right);
	printf("\n");
}
