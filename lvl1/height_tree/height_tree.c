#include <stdlib.h>

struct s_node {
    int           value;
    struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
    int tmp = 0;
    int max = 0;
    if (root != NULL)
    {
        for (int i = 0; root->nodes[i]; i++)
        {
            tmp = height_tree(root->nodes[i]) + 1;
            if (tmp > max)
                max = tmp;
        }
    }
    return max;
}
