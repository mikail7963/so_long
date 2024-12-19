/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:12:08 by mikkayma          #+#    #+#             */
/*   Updated: 2024/11/06 17:46:28 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexadecimal(unsigned long value, char format, int len)
{
	char			s[32];
	unsigned long	tmp;
	int				s_len;

	s_len = len;
	tmp = value;
	while (value > 0)
	{
		tmp = value % 16;
		if (tmp >= 10)
		{
			if (format == 'X')
				s[--len] = (tmp - 10) + 'A';
			else
				s[--len] = (tmp - 10) + 'a';
		}
		else
			s[--len] = tmp + '0';
		value /= 16;
	}
	write(1, s, s_len);
	return (s_len);
}

static int	ft_void_format(const char format, va_list args)
{
	int				len;
	unsigned long	tmp;
	unsigned long	address;
	void			*ptr;

	ptr = va_arg(args, void *);
	address = (unsigned long)ptr;
	tmp = address;
	len = 0;
	while (tmp > 0 && len++ >= 0)
		tmp /= 16;
	if (address == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_hexadecimal(address, format, len);
	len += 2;
	return (len);
}

int	ft_hexadecimal_format(const char format, va_list args)
{
	int				len;
	unsigned long	x;
	unsigned long	tmp;

	len = 0;
	if (format == 'x' || format == 'X')
	{
		x = va_arg(args, unsigned int);
		tmp = x;
		if (x == 0)
		{
			write(1, "0", 1);
			return (1);
		}
		while (tmp > 0 && len++ >= 0)
			tmp /= 16;
		ft_hexadecimal(x, format, len);
	}
	if (format == 'p')
		len = ft_void_format(format, args);
	return (len);
}
