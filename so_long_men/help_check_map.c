/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:28:10 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:52:24 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all_maps(char **s, t_win *index)
{
	if (!check_square(s) || !check_wall(s) || !check_player(s) || !check_exit(s)
		|| !check_0_c(s, index) || !check_imposter(s))
	{
		ft_printf("invalid map");
		exit(0);
	}
}

void	check_col(char **map)
{
	if (!check_collect(map))
	{
		ft_printf("invalid map");
		exit(0);
	}
}

void	check_ber(char *s)
{
	if (strncmp(s + (ft_strlen(s) - 4), ".ber", 4))
	{
		ft_printf("please put a .ber in your name file");
		exit(0);
	}
}

void	space(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
	{
		ft_printf("Please put a created map");
		exit(0);
	}
	while (s[i])
	{
		if ((s[i] == '\n' && s[i + 1] == '\n') || s[0] == '\n')
		{
			ft_printf("invalid map");
			exit(0);
		}
		i++;
	}
	if (s[ft_strlen(s) - 1] == '\n')
	{
		{
			ft_printf("invalid map");
			exit(0);
		}
	}
}
