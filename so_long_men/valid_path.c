/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:58:45 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:52:42 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_ligne(char **str)
{
	int	x;
	int	y;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			x++;
		}
		y++;
	}
	return (y);
}

char	**dup_map(char **str)
{
	int		i;
	char	**map2;

	i = 0;
	map2 = (char **)malloc(sizeof(char *) * (count_ligne(str) + 1));
	while (str[i])
	{
		map2[i] = ft_strdup(str[i]);
		i++;
	}
	map2[i] = NULL;
	return (map2);
}

void	my_flood_p(int x, int y, char **str)
{
	if (str[x][y] != 'P' && str[x][y] != 'C' && str[x][y] != '0')
		return ;
	str[x][y] = 'K';
	my_flood_p(x + 1, y, str);
	my_flood_p(x - 1, y, str);
	my_flood_p(x, y + 1, str);
	my_flood_p(x, y - 1, str);
	return ;
}

void	my_flood_e(int x, int y, char **str)
{
	if (str[x][y] != 'E' && str[x][y] != 'C' && str[x][y] != '0')
		return ;
	str[x][y] = 'K';
	my_flood_e(x + 1, y, str);
	my_flood_e(x - 1, y, str);
	my_flood_e(x, y + 1, str);
	my_flood_e(x, y - 1, str);
	return ;
}

int	check_collect(char **str)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
