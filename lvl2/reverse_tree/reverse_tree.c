#include <stdlib.h>

struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
};


void reverse_tree(struct s_node *root)
{
    if (root != NULL)
    {
        struct s_node *tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        reverse_tree(root->right);
        reverse_tree(root->left);
    }
}

// void   print_infix(struct s_node *root)
// {
//     if (!root)
//         return ;
//     if (root->left)
//         print_infix(root->left);
//     printf("%d\n", root->value);
//     if (root->right)
//         print_infix(root->right);
// }

// int     main()
// {
//     struct s_node *root = (struct s_node *)malloc(sizeof(struct s_node));
//     root = NULL;
//     // root->value = 94;
//     // root->left = (struct s_node *)malloc(sizeof(struct s_node));
//     // root->left->value = 17;
//     // root->left->left = (struct s_node *)malloc(sizeof(struct s_node));
//     // root->left->left->value = 40;
//     // root->left->left->left = NULL;
//     // root->left->left->right = NULL;
//     // root->left->right = (struct s_node *)malloc(sizeof(struct s_node));
//     // root->left->right->value = 12;
//     // root->left->right->right = NULL;
//     // root->left->right->left = NULL;
//     // root->right = (struct s_node *)malloc(sizeof(struct s_node));
//     // root->right->value = 35;
//     // root->right->right = NULL;
//     // root->right->left = NULL;
//     //
//     // print_infix(root);
//     //
//     reverse_tree(root);
//     printf("\n");
//
//     // print_infix(root);
// }
