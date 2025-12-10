/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:08:31 by jodone            #+#    #+#             */
/*   Updated: 2025/12/02 17:34:40 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		lens1;
	int		lens2;
	int		i;

	lens1 = 0;
	if (s1)
		lens1 = ft_strlen(s1);
	result = malloc((lens1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
		result[i] = s1[i++];
	lens1 = 0;
	while (s2[lens1])
		result[i++] = s2[lens1++];
	result[i] = '\0';
	free(s1);
	return (result);
}
