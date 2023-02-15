/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:08:56 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:13:27 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_men/so_long.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char *)malloc((sizeof(char) * ft_strlen(src)) + 1);
	if (!dest)
		return (0);
	dest = ft_strcpy(dest, src);
	return (dest);
}
