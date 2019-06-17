/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:42:30 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 09:52:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
        int value;
        struct s_node *next;
}		t_node;

int     is_looping(struct s_node *node);

t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->value = value;
	new->next = NULL;
	return (new);
}


int		main(void)
{
	t_node	*head;

	head = new_node(1);
	head->next = head;
	//head->next->next = new_node(3);
	//head->next->next->next = new_node(4);
	//head->next->next->next->next = head->next->next->next;
	//head->next->next->next->next->next = new_node(6);
	//head->next->next->next->next->next->next = head->next->next->next->next->next;
	printf("looping = %d\n", is_looping(head));
	return (1);
}
