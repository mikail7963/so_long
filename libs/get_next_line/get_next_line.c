/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:52:13 by mikkayma          #+#    #+#             */
/*   Updated: 2024/12/17 16:42:36 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_print_line(char **tmp)
{
	int		n_pos;
	char	*line;
	char	*str;

	if (!*tmp)
		return (NULL);
	str = *tmp;
	n_pos = 0;
	while (str[n_pos] && str[n_pos] != 10)
		n_pos++;
	if (str[n_pos] == 10)
		n_pos++;
	line = ft_strlendup(str, n_pos);
	*tmp = ft_strlendup(str + n_pos, ft_strlen(str + n_pos));
	free(str);
	str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buffer;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(str), str = NULL, NULL);
	if (have_10(str))
		return (ft_print_line(&str));
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(str), str = NULL, free(buffer), buffer = NULL, NULL);
		buffer[bytes_read] = '\0';
		str = ft_strjoinn(str, buffer);
		if (have_10(str))
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (ft_print_line(&str));
}
