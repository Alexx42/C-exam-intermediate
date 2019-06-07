/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:31:39 by exam              #+#    #+#             */
/*   Updated: 2019/06/04 12:17:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
        int value;
        struct s_node *left;
        struct s_node *right;
};

void			height_tree(struct s_node *node, int height, int *save)
{
	if (!node)
		return ;
	if (node->left || node->right)
		height++;
	if (height > *save)
		*save = height;
	height_tree(node->left, height, save);
	height_tree(node->right, height, save);
}

void	iter(struct s_node *node, int *save)
{
	int		a = 0;
	int		b = 0;
	int		var = 0;
	if (!node)
		return ;

	height_tree(node->left, 1, &var);
	a = var;
	var = 0;
	height_tree(node->right, 1, &var);
	b = var;
	if (a + b + 1 > *save)
		*save = a + b + 1;
	iter(node->left, save);
	iter(node->right, save);
}

int     width_tree(struct s_node *n)
{
	int		save = 1;

	if (!n)
		return (0);
	iter(n, &save);
	return (save);
}
