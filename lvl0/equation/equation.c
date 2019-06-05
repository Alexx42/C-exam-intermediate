#include <stdio.h>


void       print_equation(int i, int j, int k, int n)
{
    if ((((i * 10) + j) + (k * 10) + i) == n)
        printf("A = %d, B = %d, C = %d\n", i, j, k);
}

void    equation(int n)
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                print_equation(i, j, k, n);
            }
        }
    }
}
