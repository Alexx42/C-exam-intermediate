#include "t_point.h"
#include <stdio.h>
#include <stdlib.h>


//void    print_tab(char **area)
//{
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			printf("%c ", area[i][j]);
//		}
//        printf("\n");
//	}
//}
//
//char    **make_area(char **zone)
//{
//    int row = 0;
//    int col = 0;
//    char **res;
//    res = (char **)malloc(sizeof(char *) * 5);
//    for (int i = 0; i < 5; i++)
//    {
//        res[i] = (char *)malloc(sizeof(char) * 8 + 1);
//        int k = 0;
//        for (int j = 0; j < 15; j++) {
//
//            if (zone[i][j] != ' ')
//                res[i][k++] = zone[i][j];
//        }
//    }
//    return res;
//}

void  color_map(int y, int x, char c, char **tab, t_point size)
{
    if (tab[y][x] != c)
        return ;
    if (tab[y][x] == c)
        tab[y][x] = 'F';
    if (y >= 1)
        color_map(y - 1, x, c, tab, size);
    if (y < size.y - 1)
        color_map(y + 1, x, c, tab, size);
    if (x >= 1)
        color_map(y, x - 1, c, tab, size);
    if (x < size.x - 1)
        color_map(y, x + 1, c, tab, size);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char COLOR = tab[begin.y][begin.x];
    int x = begin.x;
    int y = begin.y;

    if (tab[y][x] == COLOR)
        tab[y][x] = 'F';
    if (y >= 1)
        color_map(y - 1, x, COLOR, tab, size);
    if (y < size.y - 1)
        color_map(y + 1, x, COLOR, tab, size);
    if (x >= 1)
        color_map(y, x - 1, COLOR, tab, size);
    if (x < size.x - 1)
        color_map(y, x + 1, COLOR, tab, size);

}
//
//int main(void)
//{
//	char **area;
//	t_point size = { 8, 5 };
//	t_point begin = { 2, 2 };
//	char *zone[] = {
//		"1 1 1 1 1 1 1 1",
//		"1 0 0 0 1 0 0 1",
//		"1 0 0 1 0 0 0 1",
//		"1 0 1 1 0 0 0 1",
//		"1 1 1 0 0 0 0 1",
//	};
//	area = make_area(zone);
//	print_tab(area);
//	flood_fill(area, size, begin);
//    printf("\n");
//	print_tab(area);
////	return (0);
//}