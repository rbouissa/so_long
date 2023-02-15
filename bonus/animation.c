/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:56:48 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/15 17:57:32 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_win *index, int h, int w, int *r)
{
	if (*r == 0)
		upload_images(index, h, w, "textures/heart1.xpm");
	else if (*r == 1)
		upload_images(index, h, w, "textures/heart2.xpm");
	else if (*r == 2)
		upload_images(index, h, w, "textures/heart3.xpm");
	else if (*r == 3)
		upload_images(index, h, w, "textures/heart4.xpm");
	else if (*r == 4)
		upload_images(index, h, w, "textures/heart5.xpm");
	else if (*r == 5)
		upload_images(index, h, w, "textures/heart6.xpm");
	else if (*r == 6)
		upload_images(index, h, w, "textures/heart7.xpm");
	else if (*r == 7)
		upload_images(index, h, w, "textures/heart8.xpm");
}

void	anam(t_win *index, int j, int i, int k)
{
	upload_images(index, j, i, "textures/background.xpm");
	up(index, j, i, &k);
}

int	movvv(t_win *index)
{
	static int	m;
	static int	k;
	int			i;
	int			j;

	i = 0;
	if (m % 700 == 0)
	{
		while (index->str[i])
		{
			j = 0;
			while (index->str[i][j])
			{
				if (index->str[i][j] == 'C')
					anam(index, j, i, k);
				j++;
			}
			i++;
		}
		k++;
		if (k == 8)
			k = 0;
	}
	m++;
	return (0);
}
