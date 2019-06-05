#include <stdlib.h>

typedef struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
}               t_node;


//t_node  *init_node(int val)
//{
//    t_node *n = (t_node *)malloc(sizeof(t_node));
//    n->left = NULL;
//    n->right = NULL;
//    n->value = val;
//    return n;
//}

void count_tree(t_node *node, int *val, int expected, int length)
{
    if (node == NULL)
        return ;
    if (node->value == expected)
        length++;
    else
        length = 1;
    if (length > *val)
        *val = length;
    count_tree(node->right, val, node->value + 1, length);
    count_tree(node->left, val, node->value + 1, length);
}

int	longest_sequence(t_node *node)
{
    int val = 1;
    if (!node)
        return 0;
    count_tree(node, &val, node->value, 0);
    return val;
}

//int         main()
//{
//    t_node *n = init_node(10);
//    n->left = init_node(5);
//    n->right = init_node(17);
//    n->left->right = init_node(9);
//    n->left->left = init_node(6);
//    n->left->left->left = init_node(7);
//    n->left->left->left->right = init_node(8);
//    n->left->left->right = init_node(13);
//
//    printf("%d\n", longest_sequence(n));
//}



