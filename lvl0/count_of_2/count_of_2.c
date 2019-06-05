
int    count_of_2(int n)
{
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 == 2)
                count++;
            tmp = tmp / 10;
        }
    }
    return (count);
}
