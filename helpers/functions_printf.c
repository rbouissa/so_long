/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:34:20 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/01 22:03:05 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_string("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_character(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_decimal(long c)
{
	int	sign;

	sign = 0;
	if (c < 0)
	{
		ft_character('-');
		c = -c;
		sign = 1;
	}
	if (c >= 10)
		return (ft_decimal(c / 10) + ft_decimal(c % 10) + sign);
	else
	{
		return (ft_character(c + 48) + sign);
	}
}

int	ft_unsigned_decimal(long c)
{
	if (c < 0)
		c = (-1) * c;
	return (ft_decimal(c));
}

int	hx(char *base, unsigned int c)
{
	if (c >= 16)
		return (hx(base, c / 16) + hx(base, c % 16));
	else
	{
		return (ft_character(base[c]));
	}
}
