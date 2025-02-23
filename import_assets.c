/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:18:24 by mikkayma          #+#    #+#             */
/*   Updated: 2025/02/23 17:03:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_import_other(t_game *game)
{
	int	w;
	int	h;

	game->floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&w, &h);
	if (game->floor == NULL)
		handle_error("xpm error floor", game, 1);
	game->key = mlx_xpm_file_to_image(game->mlx, "assets/Key.xpm", &w, &h);
	if (game->key == NULL)
		handle_error("xpm error key", game, 1);
	game->lock_exit = mlx_xpm_file_to_image(game->mlx, "assets/Exit.xpm",
			&w, &h);
	if (game->lock_exit == NULL)
		handle_error("xpm error exit", game, 1);
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall/Wall.xpm",
			&w, &h);
	if (game->wall == NULL)
		handle_error("xpm error wall", game, 1);
}

void	assets_import_wall(t_game *game)
{
	int	w;
	int	h;

	game->wall_ld = mlx_xpm_file_to_image(game->mlx,
			"assets/wall/wall_LD.xpm", &w, &h);
	if (game->wall_ld == NULL)
		handle_error("xpm error wall ld", game, 1);
	game->wall_lu = mlx_xpm_file_to_image(game->mlx,
			"assets/wall/wall_LU.xpm", &w, &h);
	if (game->wall_lu == NULL)
		handle_error("xpm error wall lu", game, 1);
	game->wall_rd = mlx_xpm_file_to_image(game->mlx,
			"assets/wall/wall_RD.xpm", &w, &h);
	if (game->wall_rd == NULL)
		handle_error("xpm error wall rd", game, 1);
	game->wall_ru = mlx_xpm_file_to_image(game->mlx,
			"assets/wall/wall_RU.xpm", &w, &h);
	if (game->wall_ru == NULL)
		handle_error("xpm error wall ru", game, 1);
}

void	assets_import(t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	import_sprite_w(game, w, h);
	import_sprite_a(game, w, h);
	import_sprite_s(game, w, h);
	import_sprite_d(game, w, h);
	import_exit_sprite(game, w, h);
	assets_import_wall(game);
	assets_import_other(game);
	import_enemy_assets(game);
	game->vertical_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall/vertical_wall.xpm", &w, &h);
	if (game->vertical_wall == NULL)
		handle_error("xpm error verticall wall", game, 1);
	game->horizontal_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall/horizontal_wall.xpm", &w, &h);
	if (game->horizontal_wall == NULL)
		handle_error("xpm error horizontal wall", game, 1);
}
