/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:05:02 by rbouissa          #+#    #+#             */
/*   Updated: 2023/01/06 17:26:49 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_string(char *str);
int	ft_character(char c);
int	ft_decimal(long c);
int	ft_unsigned_decimal(long c);
int	hx(char *base, unsigned int c);
int	ft_add(char *base, size_t c);

#endif
