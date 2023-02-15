/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:53 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/15 17:59:31 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd, t_win *index)
{
	char	*buf;
	char	*str;
	char	**split;
	int		i;

	i = 0;
	str = ft_calloc(1, 1);
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		str = ft_strjoin(str, buf);
		free(buf);
	}
	space(str);
	split = ft_split(str, '\n');
	index->w = ft_strlen(split[0]);
	index->h = 0;
	while (split[index->h] != NULL)
		index->h++;
	free(str);
	return (split);
}

void	put_image(int y, int w, t_win *index, char **s)
{
	int	x;
	int	h;

	x = 0;
	h = 0;
	while (s[y][x] != '\0')
	{
		upload_images(index, h, w, "textures/background.xpm");
		if (s[y][x] == '1')
			upload_images(index, h, w, "textures/wall.xpm");
		if (s[y][x] == 'P')
		{
			upload_images(index, h, w, "textures/player.xpm");
			index->ind.x = x;
			index->ind.y = y;
		}
		if (s[y][x] == 'C')
			upload_images(index, h, w, "textures/collective.xpm");
		if (s[y][x] == 'E')
			upload_images(index, h, w, "textures/exit.xpm");
		x++;
		h++;
	}
}

void	split_map(char **s, t_win *index)
{
	int	y;
	int	w;

	w = 0;
	y = 0;
	while (1)
	{
		put_image(y, w, index, s);
		w++;
		y++;
		if (s[y] == '\0')
		{
			break ;
		}
	}
}

int	main(int argc, char *argv[])
{
	static t_win	index;
	int				keycode;
	char			**map;
	int				fd;

	keycode = 0;
	if (argc == 2)
	{
		check_ber(argv[1]);
		fd = open(argv[1], O_RDONLY);
		index.str = read_map(fd, &index);
		map = dup_map(index.str);
		index.mlx = mlx_init();
		index.mlx_win = mlx_new_window(index.mlx, index.w * 50, index.h * 50,
				"solong");
		split_map(index.str, &index);
		check_all_maps(index.str, &index);
		my_flood_p(index.ind.y, index.ind.x, map);
		my_flood_e(index.ind.y, index.ind.x, map);
		check_col(map);
		mlx_key_hook(index.mlx_win, key_hook, &index);
		mlx_hook(index.mlx_win, 17, 0, (void *)exit, &index);
		mlx_loop(index.mlx);
	}
	return (0);
}
