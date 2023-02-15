/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:40:42 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:12:42 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_men/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	i;

	i = 0;
	dest = malloc(count * size);
	if (!dest)
		return (0);
	while (i < count * size)
	{
		((unsigned char *)dest)[i] = 0;
		i ++;
	}
	return (dest);
}
