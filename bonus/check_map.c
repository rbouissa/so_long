/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:02:10 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/10 15:05:42 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_square(char **s)
{
	int	x;
	int	y;
	int	cmpt;

	cmpt = 0;
	y = 0;
	x = 0;
	while (s[y][x])
	{
		x++;
		cmpt++;
	}
	while (s[y])
	{
		x = 0;
		while (s[y][x])
			x++;
		if (cmpt != x)
			return (0);
		y++;
	}
	return (1);
}

int	check_wall(char **s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s[y])
		y++;
	y--;
	while (s[y][x])
	{
		if (s[y][x] != '1' || s[0][x] != '1')
			return (0);
		x++;
	}
	x--;
	while (y)
	{
		if (s[y][x] != '1' || s[y][0] != '1')
			return (0);
		y--;
	}
	return (1);
}

int	check_player(char **st)
{
	int	x;
	int	y;
	int	cmpt;

	x = 0;
	y = 0;
	cmpt = 0;
	while (1)
	{
		x = 0;
		while (st[y][x] != '\0')
		{
			if (st[y][x] == 'P')
				cmpt++;
			x++;
		}
		y++;
		if (st[y] == '\0')
			break ;
	}
	if (cmpt != 1)
		return (0);
	else
		return (1);
}

int	check_exit(char **st)
{
	int	x;
	int	y;
	int	cmpt;

	x = 0;
	y = 0;
	cmpt = 0;
	while (1)
	{
		x = 0;
		while (st[y][x] != '\0')
		{
			if (st[y][x] == 'E')
				cmpt++;
			x++;
		}
		y++;
		if (st[y] == '\0')
			break ;
	}
	if (cmpt != 1)
		return (0);
	else
		return (1);
}

int	check_0_c(char **st, t_win *index)
{
	int	x;
	int	y;
	int	cmpt;

	x = 0;
	y = 0;
	cmpt = 0;
	index->cmpt = 0;
	while (st[y])
	{
		x = 0;
		while (st[y][x] != '\0')
		{
			if (st[y][x] == '0')
				cmpt++;
			if (st[y][x] == 'C')
				index->cmpt++;
			x++;
		}
		y++;
	}
	if (!cmpt && !index->cmpt)
		return (0);
	else
		return (1);
}
