/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:26 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:52:37 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../helpers/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct player
{
	int		x;
	int		y;
}			t_pl;

typedef struct window
{
	void	*mlx;
	void	*mlx_win;
	int		h;
	int		w;
	int		x;
	int		y;
	int		cmpt;
	int		cmpt_mv;
	char	**str;
	t_pl	ind;
}			t_win;
void		split_map(char **s, t_win *index);
char		**read_map(int fd, t_win *index);
void		upload_images(t_win *index, int height, int width, char *s);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);
int			key_hook(int keycode, t_win *index);
int			check_0_c(char **st, t_win *index);
int			check_exit(char **st);
int			check_player(char **st);
int			check_wall(char **s);
int			check_square(char **s);
int			check_collect(char **str);
void		my_flood_e(int x, int y, char **str);
void		my_flood_p(int x, int y, char **str);
char		**dup_map(char **str);
char		*ft_itoa(int n);
char		*ft_strdup(char *src);
int			check_imposter(char **s);
void		lala_a(t_win *in);
void		lala_d(t_win *in);
void		lala_w(t_win *in);
void		lala_s(t_win *in);
void		wiwi_print(t_win *in);
void		check_all_maps(char **s, t_win *index);
void		check_ber(char *s);
void		space(char *s);
void		check_col(char **map);

#endif
