/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_dames.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:45:17 by jodone            #+#    #+#             */
/*   Updated: 2025/12/10 14:34:02 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	queen_check(int *display, int number, int index)
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

void	set_queens(int *display, int nb_queens, int index)
{
	int	number;

	number = 0;
	if (index >= nb_queens)
	{
		while (number < nb_queens)
		{
			printf("%i", display[number]);
			number++;
		}
		printf("\n");
		return ;
	}
	while (number < nb_queens)
	{
		if (queen_check(display, number, index) == 0)
		{
			display[index] = number;
			set_queens(display, nb_queens, index + 1);
		}
		number++;
	}
}

int	main(int ac, char **av)
{
	int	*display;
	int	nb_queens;

	if (ac != 2)
		return (0);
	nb_queens = atoi(av[1]);
	display = malloc(nb_queens * sizeof(int));
	set_queens(display, nb_queens, 0);
	free(display);
}
