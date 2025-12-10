/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:13:47 by jodone            #+#    #+#             */
/*   Updated: 2025/11/13 13:23:23 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	uint8_t out;
	uint8_t mask;
	uint8_t bit;
	int i;
	
	out = 0;
	i = 0;
	while (i < 4)
	{
		mask = 1 << (7 - i);
		bit = (mask & octet) >> (7 - 2 * i);
		out = out | bit;
		mask = 1 << i;
		bit = (mask & octet) << (7 - 2 * i);
		out = out | bit;
		i++;
	}
	return (out);
}

void print_binary(uint8_t n)
{
	int	i;
	uint8_t mask;
	
	i = 0;
	while (i < 8)
	{
		mask = 1 << (7 - i);
		if (i==4)
			write(1, " ", 1);
		if (mask & n)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
}

int	main()
{
	uint8_t byte = 5;
	
	print_binary(byte);
	write(1, "\n", 1);
	print_binary(reverse_bits(byte));
}