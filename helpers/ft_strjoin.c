/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:15:01 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:13:33 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_men/so_long.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	dest = (char *) malloc(sizeof(char) * (ft_strlen(s2)+ft_strlen(s1) + 1));
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i ++;
	}
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	return (dest);
}
