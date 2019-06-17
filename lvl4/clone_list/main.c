/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:42:30 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 12:14:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
        int data;
        struct s_node *next;
        struct s_node *other;
}		t_node;


struct s_node *clone_list(struct s_node *node);

t_node	*new_node(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->next = NULL;
	new->other = NULL;
	return (new);
}

void	print_list(t_node *head1, t_node *head2)
{
	while (head1)
	{
		if (!head2)
		{
			printf("you fucked up\n");
			return ;
		}
		printf("%d == %d\n", head1->data, head2->data);
		if (head1->other == NULL && head2->other != NULL)
			printf("(null) is bad\n");
		else if (head1->other == NULL && head2->other == NULL)
			printf("(null) is good\n");
		else
			printf("%d == %d\n", head1->other->data, head2->other->data);
		head1 = head1->next;
		head2 = head2->next;
	}
}

int		main(void)
{
	t_node	*root;
	t_node	*clone;

	root = new_node(1);
	root->next = new_node(2);
	root->other = root->next;
	root->next->other = root->next;
	//root->next->next = new_node(3);
	//root->next->next->next = new_node(4);
	//root->next->next->next->other = root->next->next;
	//root->next->other = root->next->next->next->next;
	clone = clone_list(root);
	print_list(root, clone);
	return (1);
}
