/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:30:34 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 09:52:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node {
        int value;
        struct s_node *next;
}			t_node;

int     is_looping(t_node *node)
{
	t_node	*fast;
	t_node	*slow;

	if (!node || !node->next)
		return (0);
	fast = node->next;
	slow = node;
	while (slow && fast)
	{
		if (slow == fast)
			return (1);
		slow = slow->next;
		if (fast->next)
			fast = fast->next->next;
		else
			return (0);
	}
	return (0);
}
