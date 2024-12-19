/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:25:56 by mikkayma          #+#    #+#             */
/*   Updated: 2024/12/19 14:41:49 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**clonemap(t_game *game)
{
	int		i;
	char	**clone;

	i = 0;
	clone = malloc(sizeof(char *) * game->map_y + 1);
	if (!clone)
		handle_error("malloc error", game, 1);
	while (i < game->map_y)
	{
		clone[i] = ft_strdup(game->map[i]);
		i++;
	}
	return (clone);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_clone(char **map_clone, int map_y)
{
	int	i;

	i = 0;
	while (i < map_y)
	{
		free(map_clone[i]);
		i++;
	}
	free(map_clone);
}

char	**fullmap_import(char *folder, char **fullmap, t_game *game)
{
	int		fd;
	char	*line;
	int		i;
	int		map_c;

	map_c = 0;
	fd = open(folder, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		fullmap[map_c] = ft_strdup(line);
		i = 0;
		while (line[i] != '\0')
		{
			objects(line[i], game, map_c, i);
			i++;
		}
		free(line);
		map_c++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (fullmap);
}

void	map(char *folder, t_game *game)
{
	char	**fullmap;
	int		folder_check;

	folder_check = ft_strlen(folder);
	game->error = 0;
	game->exit = 0;
	game->coin = 0;
	game->move = 0;
	game->enemy_way = 0;
	game->hero_way = 0;
	game->is_moving = 0;
	game->enemy_c = 0;
	if (folder[folder_check - 4] == '.' && folder[folder_check - 3] == 'b'
		&& folder[folder_check - 2] == 'e' && folder[folder_check - 1] == 'r')
		map_linecheck(folder, game);
	else
		handle_error("error file extension is wrong", game, 0);
	fullmap = malloc(sizeof(char *) * game->map_y);
	if (fullmap == NULL)
		handle_error("memory error", game, 1);
	game->map = fullmap_import(folder, fullmap, game);
	game->map_x = ft_strlen(game->map[0]) - 1;
	if (game->enemy_c > 0)
		enemy_location(game);
}
