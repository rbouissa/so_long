/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_me_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:32 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/15 17:54:52 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lala_a(t_win *in)
{
	upload_images(in, in->ind.x, in->ind.y, "textures/background.xpm");
	in->ind.x--;
	upload_images(in, in->ind.x, in->ind.y, "textures/player.xpm");
	in->str[in->ind.y][in->ind.x] = 'P';
	in->str[in->ind.y][in->ind.x + 1] = '0';
}

void	lala_d(t_win *in)
{
	upload_images(in, in->ind.x, in->ind.y, "textures/background.xpm");
	in->ind.x++;
	upload_images(in, in->ind.x, in->ind.y, "textures/player.xpm");
	in->str[in->ind.y][in->ind.x] = 'P';
	in->str[in->ind.y][in->ind.x - 1] = '0';
}

void	lala_s(t_win *in)
{
	upload_images(in, in->ind.x, in->ind.y, "textures/background.xpm");
	in->ind.y++;
	upload_images(in, in->ind.x, in->ind.y, "textures/player.xpm");
	in->str[in->ind.y][in->ind.x] = 'P';
	in->str[in->ind.y - 1][in->ind.x] = '0';
}

void	lala_w(t_win *in)
{
	upload_images(in, in->ind.x, in->ind.y, "textures/background.xpm");
	in->ind.y--;
	upload_images(in, in->ind.x, in->ind.y, "textures/player.xpm");
	in->str[in->ind.y][in->ind.x] = 'P';
	in->str[in->ind.y + 1][in->ind.x] = '0';
}

void	wiwi_print(char c, t_win *in)
{
	char	*i;

	i = ft_itoa(in->cmpt_mv);
	mlx_string_put(in->mlx, in->mlx_win, 10, 10, 0, i);
	free(i);
	if (c == 'E')
		ft_printf("YOU WIN BIMO IS HAPPY");
	else if (c == 'A')
		ft_printf("YOU LOSE BIMO IS SAD");
	exit(0);
}
