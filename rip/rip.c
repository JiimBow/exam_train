/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:47:37 by jodone            #+#    #+#             */
/*   Updated: 2025/12/11 18:37:42 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_sol(char *str, int len, int stable)
{
	int	count;
	int	space;
	int	i;

	i = 0;
	count = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == '(')
			count++;
		if (str[i] == ')')
			count--;
		if (str[i] == ' ')
			space++;
		if (count < 0)
			return ;
		i++;
	}
	if (space == stable)
	{
		write(1, str, len);
		write(1, "\n", 1);
	}
}

void	rip(char *str, int index, int len, int stable)
{
	char c;

	if (index == len)
	{
		check_sol(str, len, stable);
		return ;
	}
	c = str[index];
	str[index] = ' ';
	rip(str, index + 1, len, stable);
	str[index] = c;
	rip(str, index + 1, len, stable);
}

int	main(int ac, char **av)
{
	int	len;
	int	diff;
	int	stable;

	if (ac != 2)
		return (1);
	len = 0;
	diff = 0;
	stable = 0;
	while (av[1][len])
	{
		if (av[1][len] != '(' && av[1][len] != ')')
			return (1);
		if (av[1][len] == '(')
			diff++;
		if (av[1][len] == ')')
		{
			if (diff > 0)
				diff--;
			else
				stable++;
		}
		len++;
	}
	rip(av[1], 0, len, stable + diff);
}



