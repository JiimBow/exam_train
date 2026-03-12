/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_dames2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:37:16 by jodone            #+#    #+#             */
/*   Updated: 2025/12/15 15:55:38 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	check_queen(int *display, int index, int number)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (display[i] == number)
			return (1);
		if (display[i] + (index - i) == number)
			return (1);
		if (display[i] - (index - i) == number)
			return (1);
		i++;
	}
	return (0);
}

void	put_queens(int *display, int index, int size)
{
	int	number;

	number = 0;
	if (index >= size)
	{
		while (number < size)
		{
			printf("%i", display[number]);
			number++;
		}
		printf("\n");
		return ;
	}
	while (number < size)
	{
		if (check_queen(display, index, number) == 0)
		{
			display[index] = number;
			put_queens(display, index + 1, size);
		}
		number++;
	}
}

int	main(int ac, char **av)
{
	int	*display;
	int	size;

	if (ac != 2)
		return (1);
	size = atoi(av[1]);
	display = malloc(size * sizeof(int));
	put_queens(display, 0, size);
	free(display);
}