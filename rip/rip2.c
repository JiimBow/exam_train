/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:02:41 by jodone            #+#    #+#             */
/*   Updated: 2025/12/15 16:22:15 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rip_check(char *av, int diff, int len)
{
	int	count;
	int	space;
	int	i;

	count = 0;
	space = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] == '(')
			count++;
		if (av[i] == ')')
			count--;
		if (av[i] == ' ')
			space++;
		if (count < 0)
			return ;
		i++;
	}
	if (count == 0 && space == diff)
	{
		write(1, av, len);
		write(1, "\n", 1);
	}
}

void	rip(char *av, int index, int diff, int len)
{
	char	c;

	if (index == len)
	{
		rip_check(av, diff, len);
		return ;
	}
	c = av[index];
	av[index] = ' ';
	rip(av, index + 1, diff, len);
	av[index] = c;
	rip(av, index + 1, diff, len);
}

int	main(int ac, char **av)
{
	int	diff;
	int	stable;
	int	len;

	if (ac != 2)
		return (1);
	diff = 0;
	stable = 0;
	len = 0;
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
	rip(av[1], 0, diff + stable, len);
}
