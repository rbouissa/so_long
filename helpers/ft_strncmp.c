/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:26:07 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:13:36 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_men/so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 == NULL && n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && s1[i] == s2[i])
		i++;
	if (!(i < n))
		return (0);
	if (n == 0)
		return (0);
	if ((s1[i] - s2[i]) < 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else if ((s1[i] - s2[i]) > 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}
