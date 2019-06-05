#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
    if (na == 0 || nb == 0)
    {
        printf("\n");
        return ;
    }
    int     i = 0;
    int     j = 0;
    int count = 0;

    while (i < na && j < nb)
    {
        if (a[i] < b[j])
            i++;
        if (b[j] < a[i])
            j++;
        if (a[i] == b[j])
        {
            if (count)
                printf(" %d", a[i]);
            else
                printf("%d", a[i]);
            i++;
            j++;
            count = 1;
        }
    }
    printf("\n");
}
