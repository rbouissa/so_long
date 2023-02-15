/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:10:20 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/11 20:13:17 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_men/so_long.h"

static int	ft_intlen(int numb)
{
	int	cmpt;

	cmpt = 0;
	if (numb == 0)
	{
		cmpt ++;
	}
	if (numb < 0)
	{
		numb = numb * (-1);
		cmpt ++;
	}
	while (numb != 0)
	{
		numb = numb / 10;
		cmpt ++;
	}
	return (cmpt);
}

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*numb;

	j = n;
	numb = (char *)(malloc (sizeof(char) * ft_intlen(n) + 1));
	i = ft_intlen(n) - 1;
	if (!numb)
		return (0);
	if (j < 0)
	{
		j = j * (-1);
		numb[0] = '-';
	}
	while (j != 0)
	{
		numb[i] = j % 10 + 48;
		j = j / 10;
		i --;
	}
	if (n == 0)
		numb[0] = '0';
	numb[ft_intlen(n)] = '\0';
	return (numb);
}
