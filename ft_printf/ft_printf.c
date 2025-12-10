/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:16:08 by jodone            #+#    #+#             */
/*   Updated: 2025/12/02 15:27:47 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_format(char *fmt, int i, va_list args)
{
	if (fmt[i + 1] == 's')
		return (ft_putstr(va_arg(args, char*)));
	else if (fmt[i + 1] == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (fmt[i + 1] == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	return (0);
}

int	ft_printf(char *fmt, ...)
{
	int		i;
	int		count;
	va_list args;

	i = 0;
	count = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			put_format(fmt, i, args);
			i++;
		}
		else
			count += ft_putchar(fmt[i]);
		i++;
	}
	return (count);
}
