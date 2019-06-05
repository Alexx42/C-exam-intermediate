#include <stdlib.h>
#include <stdio.h>


# define MIN(x, y) (x > y ? y : x)

int     is_bigger(int *histogram, int val, int size, int i, int *zer)
{
    if (i >= size)
        return (i);
    int tmp = i;
    int zer_tmp = 0;
    int max_right = histogram[i];
    int size_max = 0;
    int max_left = 0;
    while (tmp < size)
    {
        while (tmp < size && histogram[tmp] == 0) {
            tmp++;
            zer_tmp++;
        }
        if (tmp < size && histogram[tmp] > val) {
            *zer = zer_tmp;
            max_left = histogram[tmp];
            size_max = tmp;
            break ;
        }
        else
        {
            if (tmp < size && histogram[tmp] != 0)
            {
                if (histogram[tmp] > max_right)
                {
                    max_right = histogram[tmp];
                    size_max = tmp;
                    (*zer) = zer_tmp;
                }
            }
        }
        tmp++;
    }
    if (max_left > val)
        return tmp;
    else if (size_max != 0)
        return size_max;
    return i;
}

int    volume_histogram(int *histogram, int size)
{
    if (size == 0 || size == 1)
        return 0;
    int zer;
    int count = 0;
    int left = 0;
    int left_idx =0;
    int right = 0;
    int right_idx = 0;
    for (int i = 0; i < size;)
    {
        zer = 0;
        left = histogram[i];
        left_idx = i;
        i++;

        i = is_bigger(histogram, left, size, i, &zer);
        if (i >= size)
            break ;
        right = histogram[i];
        right_idx = i;
        for (int k = left_idx + 1; k < right_idx; k++)
        {
            count += MIN(left, right) - histogram[k];
        }
    }

    return (count);
}
//
//int     main()
//{
////    int    histogram[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
////    int    size = 16;
//
//    int    histogram[] = {0};
//    int    size = 14;
//
//    int count = volume_histogram(histogram, size);
//    printf("count = %d\n", count);
//
//}