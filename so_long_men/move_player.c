/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:03:11 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:52:32 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(t_win *index)
{
	char	*i;

	if (index->str[index->ind.y][index->ind.x + 1] != 1)
	{
		mlx_clear_window(index->mlx, index->mlx_win);
		split_map(index->str, index);
		if (index->str[index->ind.y][index->ind.x + 1] == '0'
			|| index->str[index->ind.y][index->ind.x + 1] == 'C')
		{
			index->cmpt_mv++;
			if (index->str[index->ind.y][index->ind.x + 1] == 'C')
				index->cmpt--;
			lala_d(index);
			i = ft_itoa(index->cmpt_mv);
			ft_printf("%s%s%s\n", "BIMO Did ", i, " move");
			free(i);
		}
		else if (index->str[index->ind.y][index->ind.x + 1] == 'E'
				&& index->cmpt == 0)
		{
			index->cmpt_mv++;
			wiwi_print(index);
		}
	}
}

void	move_a(t_win *index)
{
	char	*i;

	if (index->str[index->ind.y][index->ind.x - 1] != 1)
	{
		mlx_clear_window(index->mlx, index->mlx_win);
		split_map(index->str, index);
		if (index->str[index->ind.y][index->ind.x - 1] == '0'
			|| index->str[index->ind.y][index->ind.x - 1] == 'C')
		{
			index->cmpt_mv++;
			if (index->str[index->ind.y][index->ind.x - 1] == 'C')
				index->cmpt--;
			lala_a(index);
			i = ft_itoa(index->cmpt_mv);
			ft_printf("%s%s%s\n", "BIMO Did ", i, " Move");
			free(i);
		}
		else if (index->str[index->ind.y][index->ind.x - 1] == 'E'
				&& index->cmpt == 0)
		{
			index->cmpt_mv++;
			wiwi_print(index);
		}
	}
}

void	move_s(t_win *index)
{
	char	*i;

	if (index->str[index->ind.y + 1][index->ind.x] != 1)
	{
		mlx_clear_window(index->mlx, index->mlx_win);
		split_map(index->str, index);
		if (index->str[index->ind.y + 1][index->ind.x] == '0'
			|| index->str[index->ind.y + 1][index->ind.x] == 'C')
		{
			index->cmpt_mv++;
			if (index->str[index->ind.y + 1][index->ind.x] == 'C')
				index->cmpt--;
			lala_s(index);
			i = ft_itoa(index->cmpt_mv);
			ft_printf("%s%s%s\n", "BIMO Did ", i, " Move");
			free(i);
		}
		else if (index->str[index->ind.y + 1][index->ind.x] == 'E'
				&& index->cmpt == 0)
		{
			index->cmpt_mv++;
			wiwi_print(index);
		}
	}
}

void	move_w(t_win *index)
{
	char	*i;

	if (index->str[index->ind.y - 1][index->ind.x] != 1)
	{
		mlx_clear_window(index->mlx, index->mlx_win);
		split_map(index->str, index);
		if (index->str[index->ind.y - 1][index->ind.x] == '0'
			|| index->str[index->ind.y - 1][index->ind.x] == 'C')
		{
			if (index->str[index->ind.y - 1][index->ind.x] == 'C')
				index->cmpt--;
			lala_w(index);
			index->cmpt_mv++;
			i = ft_itoa(index->cmpt_mv);
			ft_printf("%s%s%s\n", "BIMO Did ", i, " Move");
			free(i);
		}
		else if (index->str[index->ind.y - 1][index->ind.x] == 'E'
				&& index->cmpt == 0)
		{
			index->cmpt_mv++;
			wiwi_print(index);
		}
	}
}

int	key_hook(int keycode, t_win *index)
{
	if (keycode == 2)
		move_d(index);
	else if (keycode == 0)
		move_a(index);
	else if (keycode == 13)
		move_w(index);
	else if (keycode == 1)
		move_s(index);
	else if (keycode == 53)
		exit(0);
	return (0);
}
