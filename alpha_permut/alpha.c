/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:59:26 by jodone            #+#    #+#             */
/*   Updated: 2025/12/10 14:22:12 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	is_char(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (str[i] && i < index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	shuffle(char *display, char *str, int index, int len_str)
{
	int	i;

	i = 0;
	if (index >= len_str)
	{
		printf("%s\n", display);
		return ;
	}
	while (str[i])
	{
		if (is_char(display, str[i], index) == 0)
		{
			display[index] = str[i];
			shuffle(display, str, index + 1, len_str);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*display;
	int		len_str;

	if (ac != 2)
		return (0);
	len_str = strlen(av[1]);
	display = calloc((len_str + 1), sizeof(char));
	shuffle(display, av[1], 0, len_str);
	free(display);
}