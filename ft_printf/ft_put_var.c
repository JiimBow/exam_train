/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:22:19 by jodone            #+#    #+#             */
/*   Updated: 2025/12/02 15:41:18 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i++])
		count++;
	return (write(1, str, count));
}

int	ft_putnbr(int nbr)
{
	long	nb;
	int		count;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		count;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 16)
		count += ft_putnbr_base(nb / 16, base);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
