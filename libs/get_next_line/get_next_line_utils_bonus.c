/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:49:45 by mikkayma          #+#    #+#             */
/*   Updated: 2024/11/11 18:15:32 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	have_10(char *tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*array;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (free(s1), NULL);
	if (s1)
	{
		while (s1[i])
		{
			array[i] = s1[i];
			i++;
		}
	}
	free(s1);
	j = 0;
	while (s2[j])
		array[i++] = s2[j++];
	array[i] = '\0';
	return (array);
}

char	*ft_strdup(char *str, int len)
{
	char	*array;
	int		count;

	if (!str || len <= 0)
		return (NULL);
	count = 0;
	array = (char *)malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (count < len)
	{
		array[count] = str[count];
		count++;
	}
	array[count] = '\0';
	return (array);
}
