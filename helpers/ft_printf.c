/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:40:47 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/01 22:02:32 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findpr(va_list argprint, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_character(va_arg(argprint, int));
	else if (c == 's')
		count += ft_string(va_arg(argprint, char *));
	else if (c == 'p')
	{
		count += ft_string("0x");
		count += ft_add("0123456789abcdef", va_arg(argprint, size_t));
	}
	else if (c == 'i' || c == 'd')
		count += ft_decimal(va_arg(argprint, int));
	else if (c == 'u')
		count += ft_decimal(va_arg(argprint, unsigned int));
	else if (c == 'x')
		count += hx("0123456789abcdef", va_arg(argprint, unsigned int));
	else if (c == 'X')
		count += hx("0123456789ABCDEF", va_arg(argprint, unsigned int));
	else if (c == '%')
		count += ft_character('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	argprint;
	int		count;
	int		i;

	va_start(argprint, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_findpr(argprint, str[++i]);
		}
		else
			count += ft_character(str[i]);
		i++;
	}
	return (count);
}
