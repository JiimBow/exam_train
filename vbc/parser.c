/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:49:14 by jodone            #+#    #+#             */
/*   Updated: 2026/03/12 17:49:26 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	parenthesis_parse(char *str)
{
	int	i;
	int	p_count;
	int	op_count;

	i = 0;
	p_count = 0;
	op_count = 0;
	while (str && str[i])
	{
		if (str[i] == '(')
		{
			p_count++;
			if (!isdigit(str[i + 1]) && str[i + 1] != '(')
			{
				printf("Unexpected token '%c'\n", str[i]);
				return (1);
			}
		}
		else if (str[i] == ')')
		{
			p_count--;
			if (str[i + 1] != ')' && str[i + 1] != '+' && str[i + 1] != '*' && str[i + 1] != '\0')
			{
				printf("Unexpected token '%c'\n", str[i]);
				return (1);
			}
		}
		if (isdigit(str[i]))
			op_count++;
		else if (str[i] == '+' || str[i] == '*')
			op_count--;
		if (p_count < 0)
		{
			printf("Unexpected token '%c'\n", str[i]);
			return (1);
		}
		if (op_count < 0 || op_count > 1)
		{
			printf("Unexpected token '%c'\n", str[i]);
			return (1);
		}
		i++;
	}
	if (p_count != 0)
	{
		printf("Unexpected token '('\n");
		return (1);
	}
	return (0);
}

int	parser(char *str)
{
	if (parenthesis_parse(str))
		return (1);
	return (0);
}
