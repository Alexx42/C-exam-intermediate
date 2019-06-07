/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:18:21 by exam              #+#    #+#             */
/*   Updated: 2019/06/04 09:36:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

void	fn(char ch_arr[27], char c)
{
	int		i;

	i = 0;
	while (ch_arr[i])
	{
		if (ch_arr[i] == c)
			return ;
		i++;
	}
	ch_arr[i] = c;
}

int		main(int argc, char **argv)
{
	char	ch_arr[27] = {'\0'};
	int		arr[128] = {0};
	int		i;
	char	c;

	if (argc != 2)
		return (printf("\n"));
	i = 0;
	while (argv[1][i])
	{
		c = to_lower(argv[1][i]);
		if (c >= 'a' && c <= 'z')
		{
			fn(ch_arr, c);
			arr[(int)c]++;
		}
		i++;
	}
	int		first = 1;

	i = 0;
	while (ch_arr[i])
	{
		if (first)
		{
			printf("%d%c", arr[(int)ch_arr[i]], ch_arr[i]);
			first = 0;
		}
		else
			printf(", %d%c", arr[(int)ch_arr[i]], ch_arr[i]);
		i++;
	}
	printf("\n");
}
