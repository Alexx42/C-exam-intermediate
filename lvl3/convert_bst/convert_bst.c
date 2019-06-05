#include <stdlib.h>

typedef struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
}                  t_node;


t_node *c(t_node *left, t_node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    t_node *ll = left->left;
    t_node *lr = right->left;

    ll->right = right;
    right->left = ll;
    left->left = lr;
    lr->right = left;
    return left;
}

t_node *convert_bst(t_node *bst)
{
    if (bst == NULL)
        return NULL;
    t_node *left = convert_bst(bst->left);
    t_node *right = convert_bst(bst->right);

    bst->left = bst->right = bst;
    return (c(c(left, bst), right));
}

//void    print_infix(t_node *n)
//{
//    if (n == NULL)
//        return ;
//    print_infix(n->left);
//    printf("%d\n", n->value);
//    print_infix(n->right);
//}

//void    print_list(t_node *n)
//{
//    if (!n)
//        return ;
//    t_node *tmp = n;
//    while (tmp->right != n)
//    {
//        printf("%d\n", tmp->value);
//        tmp = tmp->right;
//    }
//    printf("%d\n", tmp->value);
//}
//
//t_node *init(int val)
//{
//    t_node *n = (t_node *)malloc(sizeof(t_node));
//    n->value = val;
//    n->left = NULL;
//    n->right = NULL;
//    return n;
//}
//
//int     main()
//{
//    t_node *n = init(50);
//    n->right = init(70);
//    n->left = init(15);
//    n->left->left = init(1);
//    n->left->left->left = init(0);
//
//    printf("-----TREE-----\n");
//    print_infix(n);
//    printf("\n-------LIST-----\n");
//    n = convert_bst(n);
//    print_list(n);
//}