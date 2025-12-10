/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:43:59 by jodone            #+#    #+#             */
/*   Updated: 2025/11/13 15:05:45 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char swap_bit(unsigned char octet)
{
	unsigned char	mask;
	unsigned char	bit;
	unsigned char	out;
	int				i;

	i = 0;
	out = 0;
	while (i < 4)
	{
		mask = 1 << (7 - i);
		bit = (mask & octet) >> 4;
		out |= bit;
		mask = 1 << (3 - i);
		bit = (mask & octet) << 4;
		out |= bit;
		i++;
	}
	return (out);
}

void	print_bit(unsigned char octet)
{
	int				i;
	unsigned char	mask;

	i = 0;
	while (i < 8)
	{
		mask = 1 << (7 - i);
		if (i == 4)
			write(1, " ", 1);
		if (mask & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
}

int	main()
{
	unsigned char a = 0b11000101;
	print_bit(a);
	write(1, "\n", 1);
	a = swap_bit(a);
	print_bit(a);
}