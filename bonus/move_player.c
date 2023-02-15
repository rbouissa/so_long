/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:03:11 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/15 17:55:26 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(t_win *index)
{
	char	*i;
	int		x;

	x = 10;
	if (index->str[index->ind.y][index->ind.x + 1] != 1)
	{
		if (index->str[index->ind.y][index->ind.x + 1] == '0'
			|| index->str[index->ind.y][index->ind.x + 1] == 'C')
		{
			index->cmpt_mv++;
			if (index->str[index->ind.y][index->ind.x + 1] == 'C')
				index->cmpt--;
			lala_d(index);
			i = ft_itoa(index->cmpt_mv);
			upload_images(index, 0, 0, "textures/wall.xpm");
			mlx_string_put(index->mlx, index->mlx_win, x, x, 0, i);
			free(i);
		}
		else if (index->str[index->ind.y][index->ind.x + 1] == 'E'
				&& index->cmpt == 0)
			wiwi_print('E', index);
		else if (index->str[index->ind.y][index->ind.x + 1] == 'A')
			wiwi_print('A', index);
	}
}

void	move_a(t_win *index)
{
	char	*i;
	int		x;

	x = 10;
	if (index->str[index->ind.y][index->ind.x - 1] != 1)
	{
		if (index->str[index->ind.y][index->ind.x - 1] == '0'
			|| index->str[index->ind.y][index->ind.x - 1] == 'C')
		{
			index->cmpt_mv++;
			if (index->str[index->ind.y][index->ind.x - 1] == 'C')
				index->cmpt--;
			lala_a(index);
			i = ft_itoa(index->cmpt_mv);
			upload_images(index, 0, 0, "textures/wall.xpm");
			mlx_string_put(index->mlx, index->mlx_win, x, x, 0, i);
			free(i);
		}
		else if (index->str[index->ind.y][index->ind.x - 1] == 'E'
				&& index->cmpt == 0)
			wiwi_print('E', index);
		else if (index->str[index->ind.y][index->ind.x - 1] == 'A')
			wiwi_print('A', index);
	}
}

void	move_s(t_win *index)
{
	char	*i;
	int		x;

	x = 10;
	if (index->str[index->ind.y + 1][index->ind.x] != 1)
	{
		if (index->str[index->ind.y + 1][index->ind.x] == '0'
			|| index->str[index->ind.y + 1][index->ind.x] == 'C')
		{
			index->cmpt_mv++;
			if (index->str[index->ind.y + 1][index->ind.x] == 'C')
				index->cmpt--;
			lala_s(index);
			i = ft_itoa(index->cmpt_mv);
			upload_images(index, 0, 0, "textures/wall.xpm");
			mlx_string_put(index->mlx, index->mlx_win, x, x, 0, i);
			free(i);
		}
		else if (index->str[index->ind.y + 1][index->ind.x] == 'E'
				&& index->cmpt == 0)
			wiwi_print('E', index);
		else if (index->str[index->ind.y + 1][index->ind.x] == 'A')
			wiwi_print('A', index);
	}
}

void	move_w(t_win *index)
{
	char	*i;
	int		x;

	x = 10;
	if (index->str[index->ind.y - 1][index->ind.x] != 1)
	{
		if (index->str[index->ind.y - 1][index->ind.x] == '0'
			|| index->str[index->ind.y - 1][index->ind.x] == 'C')
		{
			index->cmpt_mv++;
			if (index->str[index->ind.y - 1][index->ind.x] == 'C')
				index->cmpt--;
			lala_w(index);
			i = ft_itoa(index->cmpt_mv);
			upload_images(index, 0, 0, "textures/wall.xpm");
			mlx_string_put(index->mlx, index->mlx_win, x, x, 0, i);
			free(i);
		}
		else if (index->str[index->ind.y - 1][index->ind.x] == 'E'
				&& index->cmpt == 0)
			wiwi_print('E', index);
		else if (index->str[index->ind.y - 1][index->ind.x] == 'A')
			wiwi_print('A', index);
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
