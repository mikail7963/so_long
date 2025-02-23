/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:01:11 by mikkayma          #+#    #+#             */
/*   Updated: 2025/02/23 17:03:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	import_wall(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = x * 32;
	py = y * 32;
	if (y == 0 && x == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_lu, px, py);
	else if (y == 0 && x == game->map_x - 1)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ru, px, py);
	else if (y == game->map_y - 1 && x == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ld, px, py);
	else if (y == game->map_y - 1 && x == game->map_x - 1)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_rd, px, py);
	else if ((y == 0 || y == game->map_y - 1) && x < game->map_x - 1 && x > 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->vertical_wall, px, py);
	else if ((x == 0 || x == game->map_x - 1) && y < game->map_y - 1 && y > 0)
		mlx_put_image_to_window(game->mlx, game->win, game->horizontal_wall,
			px, py);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->wall, px, py);
	game->first_frame = 0;
}

void	map_import_window(t_game *game, int x, int y)
{
	while (y <= game->map_y - 1)
	{
		while (x < game->map_x)
		{
			if (game->map[y][x] == '1')
			{
				import_wall(game, x, y);
			}
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor,
					x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->key,
					x * 32, y * 32);
			else if (game->map[y][x] == 'E')
				play_sprite_exit(game, x * 32, y * 32);
			else if (game->map[y][x] == 'P')
				play_sprite_on_move(game);
			else if (game->map[y][x] == 'X')
				import_enemy_way(game);
			x++;
		}
		x = 0;
		y++;
	}
}
