/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:10:01 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:12:26 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_men/so_long.h"

static int	count_tab(char const *s, char c)
{
	int	i;
	int	cmpt;

	cmpt = 0;
	i = 0;
	if (!s || !c)
		return (-1);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			cmpt ++;
		while (s[i] && s[i] != c)
			i ++;
	}
	return (cmpt);
}

static int	ft_strnlen(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		i ++;
	}
	return (i);
}

static char	*ft_cp(char *src, char c)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *) malloc(sizeof(char) *(ft_strnlen(src, c) + 1));
	if (!dest)
		return (0);
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = 0;
	return (dest);
}

static	void	free_split(char **s, int z)
{
	while (z >= 0)
		free(s[z--]);
	free(s);
	return ;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		z;
	char	**split;

	i = 0;
	z = 0;
	split = (char **)malloc(sizeof(char *) * (count_tab(s, c) + 1));
	if (!split)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i] && s[i] != c)
		{
			split[z] = ft_cp((char *)s + i, c);
			if (!split[z])
				free_split(split, z);
			z ++;
		}
		while (s[i] != c && s[i])
			i ++;
	}
	split[z] = NULL;
	return (split);
}
