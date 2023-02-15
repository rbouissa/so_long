/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:04 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:52:40 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_images(t_win *index, int x, int y, char *s)
{
	int		v;
	int		p;
	void	*img;

	img = mlx_xpm_file_to_image(index->mlx, s, &v, &p);
	mlx_put_image_to_window(index->mlx, index->mlx_win, img, x * 50, y * 50);
}

int	check_imposter(char **s)
{
	int	x;
	int	y;

	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] != 'C' && s[y][x] != 'E' && s[y][x] != '1'
				&& s[y][x] != '0' && s[y][x] != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
