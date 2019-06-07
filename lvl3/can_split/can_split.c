/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:51:30 by tholzheu          #+#    #+#             */
/*   Updated: 2019/06/03 20:00:36 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
        int value;
        struct s_node *left;
        struct s_node *right;
};

int		count_nodes(struct s_node *n)
{
	if (!n)
		return (0);
	return (count_nodes(n->right) + count_nodes(n->left) + 1);
}

int		fn(struct s_node *n, int size, int *ret)
{
	if (!n)
		return (0);

	int c = fn(n->left, size, ret) + 1 + fn(n->right, size, ret);

	if (c == size - c)
		*ret = 1;
	return (c);
}

int     can_split(struct s_node *n)
{
	int		size = count_nodes(n);
	int		ret = 0;

	fn(n, size, &ret);
	return (ret);
}
