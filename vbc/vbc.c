/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:41:33 by jodone            #+#    #+#             */
/*   Updated: 2026/03/12 17:39:45 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	add_sous(char **str);
int	parser(char *str);

int	parent(char **str)
{
	int	value;

	value = 0;
	if (**str == '(')
	{
		(*str)++;
		value = add_sous(str);
		(*str)++;
		return (value);
	}
	value = *str[0] - '0';
	(*str)++;
	return (value);
}

int	mult(char **str)
{
	int		value;

	value = parent(str);
	while (**str == '*')
	{
		(*str)++;
		value *= parent(str);
	}
	return (value);
}

int	add_sous(char **str)
{
	int		value;

	value = mult(str);
	while (**str == '+')
	{
		(*str)++;
		value += mult(str);
	}
	return (value);
}

int	main(int ac, char **av)
{
	int	result;

	if (ac != 2)
		return (1);
	if (parser(av[1]))
	{
		return (1);
	}
	result = add_sous(&av[1]);
	printf("%d\n", result);
}
