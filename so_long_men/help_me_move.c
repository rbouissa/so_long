/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_me_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:36:10 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/15 17:58:40 by rbouissa         ###   ########.fr       */
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

void	wiwi_print(t_win *in)
{
	char	*i;

	i = ft_itoa(in->cmpt_mv);
	free(i);
	ft_printf("%s%s%s\n", "BIMO Did ", i, " Move");
	printf("YOU WIN BIMO IS HAPPY ");
	exit(0);
}
