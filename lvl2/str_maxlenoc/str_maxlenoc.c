/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:25:55 by tholzheu          #+#    #+#             */
/*   Updated: 2019/06/07 15:18:16 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*WARNING UGLY CODE AHEAD*/

int		ft_strlen(char *str)
{
	int		count = 0;

	while (str && str[count])
		count++;
	return (count);
}

int		find_substring(char *str, char *sub)
{
	int		sub_len = ft_strlen(sub);
	int		i = 0;
	int		j = 0;
	int		match_start = 0;
	int		match = 0;

	if (sub_len > ft_strlen(str))
		return (0);
	while (str && str[i])
	{
		if (str[i] != sub[j])
		{
			if (match > 0)
				i = match_start + 1;
			match = 0;
			j = 0;
		}
		if (str[i] == sub[j])
		{
			if (match == 0)
				match_start = i;
			match++;
			j++;
		}
		if (match == sub_len)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strncopy(char *src, int src_idx, int n)
{
	int		i = 0;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		dst[i] = src[src_idx];
		i++;
		src_idx++;
	}
	dst[i] = '\0';
	return (dst);
}

void	make_subs(char *str, char **subs)
{
	int		i = 0;
	int		cur_len = 1;
	int		j = 0;
	int		str_len = ft_strlen(str);

	while (str && str[i] && cur_len <= ft_strlen(str))
	{
		subs[j] = ft_strncopy(str, i, cur_len);
		j++;
		i++;
		if (i == str_len)
		{
			cur_len++;
			str_len--;
			i = 0;
		}
	}
	subs[j] = NULL;
}

int		size(char *str)
{
	int count = 0;
	int	len = ft_strlen(str);

	len++;
	while (len--)
		count += len;
	return (count);
}

int		main(int argc, char **argv)
{
	int		i = 1;
	int		cur_max_len = 0;
	char	**subs;
	int		j;
	int		sub_len;
	int		champ_idx = -1;
	int		count;

	if (argc < 2)
		return (write(1, "\n", 1));
	if (!argv[2])
	{
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, "\n", 1);
		return (1);
	}
	subs = (char **)malloc(sizeof(char *) * (size(argv[1]) + 1));
	make_subs(argv[1], subs);
	j = 0;
	while (subs[j])
	{
		sub_len = ft_strlen(subs[j]);
		if (sub_len < cur_max_len)
		{
			j++;
			continue ;
		}
		count = 0;
		i = 2;
		while (argv[i])
		{
			if (find_substring(argv[i], subs[j]))
				count++;
			i++;
		}
		if (count == argc - 2 && cur_max_len < sub_len)
		{
			cur_max_len = sub_len;
			champ_idx = j;
		}
		j++;
	}
	if (champ_idx == -1)
		return (write(1, "\n", 1));
	write(1, subs[champ_idx], ft_strlen(subs[champ_idx]));
	write(1, "\n", 1);
	return (1);
}
