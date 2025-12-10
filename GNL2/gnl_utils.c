/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:06:50 by jodone            #+#    #+#             */
/*   Updated: 2025/12/10 16:02:32 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str && str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		lens1;
	int		i;

	lens1 = ft_strlen(s1);
	result = calloc(lens1 + ft_strlen(s2) + 2, sizeof(char));
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	lens1 = 0;
	while (s2[lens1])
		result[i++] = s2[lens1++];
	result[i] = '\0';
	free(s1);
	return (result);
}
