/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:48:01 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 12:14:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_node {
        int           data;
        struct s_node *next;
        struct s_node *other;
}		t_node;

t_node		*new_copy_node(int data)
{
	t_node	*copy;

	copy = (t_node *)malloc(sizeof(t_node));
	copy->data = data;
	copy->next = NULL;
	copy->other = NULL;
	return (copy);
}

void		lstadd(int data, t_node **head)
{
	t_node	*new;
	t_node	*tmp;

	new = new_copy_node(data);
	if (!(*head))
		*head = new;
	else
	{
		tmp = *head;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		simple_copy(t_node *node, t_node **clone)
{
	while (node)
	{
		lstadd(node->data, clone);
		node = node->next;
	}
}

int			find_index(t_node *node, t_node *other)
{
	int		count = 0;

	while (node)
	{
		if (node == other)
			return (count);
		node = node->next;
		count++;
	}
	return (count);
}

t_node		*find_node(t_node *clone, int idx)
{
	int		i = 0;

	while (i < idx)
	{
		clone = clone->next;
		i++;
	}
	return (clone);
}

void		full_copy(t_node **node, t_node **clone)
{
	t_node	*tmp;
	t_node	*clone_tmp;
	int		idx;
	t_node	*other;

	tmp = *node;
	clone_tmp = *clone;
	while (tmp)
	{
		if (tmp->other == tmp)
			clone_tmp->other = clone_tmp;
		else if (tmp->other == NULL)
			clone_tmp->other = NULL;
		else
		{
			idx = find_index(*node, tmp->other);
			other = find_node(*clone, idx);
			clone_tmp->other = other;
		}
		tmp = tmp->next;
		clone_tmp = clone_tmp->next;
	}
}

t_node		*clone_list(t_node *node)
{
	t_node	*clone = NULL;

	if (!node)
		return (NULL);
	simple_copy(node, &clone);
	full_copy(&node, &clone);
	return (clone);
}
