#include <stdio.h>

int     sum_array(int *arr, int n)
{
    int count = 0;
    int i = 1;
    while (i < n)
    {
        count += arr[i];
        i++;
    }
    return (count);
}

int	find_pivot(int *arr, int n)
{
    int i = 0;
    int count_b = arr[0];
    int count_a = sum_array(arr, n);
    int j = i + 1;
    while (i < n && j < n)
    {
        if (count_a == count_b - arr[i])
            return (i);
        count_a -= arr[j];
        count_b += arr[i + 1];
        i++;
        j++;
    }
    return (-1);
}
