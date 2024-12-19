/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:25:28 by mikkayma          #+#    #+#             */
/*   Updated: 2024/12/18 12:11:33 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	import_sprite_w(t_game *game, int w, int h)
{
	game->sprite_w = malloc(sizeof(void *) * 8);
	game->sprite_w[0] = mlx_xpm_file_to_image(game->mlx, HERO_UP_0, &w, &h);
	if (!game->sprite_w[0])
		handle_error("xpm error,sprite_w hero 0", game, 0);
	game->sprite_w[1] = mlx_xpm_file_to_image(game->mlx, HERO_UP_1, &w, &h);
	if (!game->sprite_w[1])
		handle_error("xpm error,sprite_w hero 1", game, 0);
	game->sprite_w[2] = mlx_xpm_file_to_image(game->mlx, HERO_UP_2, &w, &h);
	if (!game->sprite_w[2])
		handle_error("xpm error,sprite_w hero 2", game, 0);
	game->sprite_w[3] = mlx_xpm_file_to_image(game->mlx, HERO_UP_3, &w, &h);
	if (!game->sprite_w[3])
		handle_error("xpm error,sprite_w hero 3", game, 0);
	game->sprite_w[4] = mlx_xpm_file_to_image(game->mlx, HERO_UP_4, &w, &h);
	if (!game->sprite_w[4])
		handle_error("xpm error,sprite_w hero 4", game, 0);
	game->sprite_w[5] = mlx_xpm_file_to_image(game->mlx, HERO_UP_5, &w, &h);
	if (!game->sprite_w[5])
		handle_error("xpm error,sprite_w hero 5", game, 0);
	game->sprite_w[6] = mlx_xpm_file_to_image(game->mlx, HERO_UP_6, &w, &h);
	if (!game->sprite_w[6])
		handle_error("xpm error,sprite_w hero 6", game, 0);
	game->sprite_w[7] = mlx_xpm_file_to_image(game->mlx, HERO_UP_7, &w, &h);
	if (!game->sprite_w[7])
		handle_error("xpm error,sprite_w hero 7", game, 0);
}

void	import_sprite_a(t_game *game, int w, int h)
{
	game->sprite_a = malloc(sizeof(void *) * 8);
	game->sprite_a[0] = mlx_xpm_file_to_image(game->mlx, HERO_LEFT_0, &w, &h);
	if (!game->sprite_a[0])
		handle_error("xpm error,sprite_a hero 0", game, 0);
	game->sprite_a[1] = mlx_xpm_file_to_image(game->mlx, HERO_LEFT_1, &w, &h);
	if (!game->sprite_a[1])
		handle_error("xpm error,sprite_a hero 1", game, 0);
	game->sprite_a[2] = mlx_xpm_file_to_image(game->mlx, HERO_LEFT_2, &w, &h);
	if (!game->sprite_a[2])
		handle_error("xpm error,sprite_a hero 2", game, 0);
	game->sprite_a[3] = mlx_xpm_file_to_image(game->mlx, HERO_LEFT_3, &w, &h);
	if (!game->sprite_a[3])
		handle_error("xpm error,sprite_a hero 3", game, 0);
	game->sprite_a[4] = mlx_xpm_file_to_image(game->mlx, HERO_LEFT_4, &w, &h);
	if (!game->sprite_a[4])
		handle_error("xpm error,sprite_a hero 4", game, 0);
	game->sprite_a[5] = mlx_xpm_file_to_image(game->mlx, HERO_LEFT_5, &w, &h);
	if (!game->sprite_a[5])
		handle_error("xpm error,sprite_a hero 5", game, 0);
	game->sprite_a[6] = mlx_xpm_file_to_image(game->mlx, HERO_LEFT_6, &w, &h);
	if (!game->sprite_a[6])
		handle_error("xpm error,sprite_a hero 6", game, 0);
	game->sprite_a[7] = mlx_xpm_file_to_image(game->mlx, HERO_LEFT_7, &w, &h);
	if (!game->sprite_a[7])
		handle_error("xpm error,sprite_a hero 7", game, 0);
}

void	import_sprite_s(t_game *game, int w, int h)
{
	game->sprite_s = malloc(sizeof(void *) * 8);
	game->sprite_s[0] = mlx_xpm_file_to_image(game->mlx, HERO_DOWN_0, &w, &h);
	if (!game->sprite_s[0])
		handle_error("xpm error,sprite_s hero 0", game, 0);
	game->sprite_s[1] = mlx_xpm_file_to_image(game->mlx, HERO_DOWN_1, &w, &h);
	if (!game->sprite_s[1])
		handle_error("xpm error,sprite_s hero 1", game, 0);
	game->sprite_s[2] = mlx_xpm_file_to_image(game->mlx, HERO_DOWN_2, &w, &h);
	if (!game->sprite_s[2])
		handle_error("xpm error,sprite_s hero 2", game, 0);
	game->sprite_s[3] = mlx_xpm_file_to_image(game->mlx, HERO_DOWN_3, &w, &h);
	if (!game->sprite_s[3])
		handle_error("xpm error,sprite_s hero 3", game, 0);
	game->sprite_s[4] = mlx_xpm_file_to_image(game->mlx, HERO_DOWN_4, &w, &h);
	if (!game->sprite_s[4])
		handle_error("xpm error,sprite_s hero 4", game, 0);
	game->sprite_s[5] = mlx_xpm_file_to_image(game->mlx, HERO_DOWN_5, &w, &h);
	if (!game->sprite_s[5])
		handle_error("xpm error,sprite_s hero 5", game, 0);
	game->sprite_s[6] = mlx_xpm_file_to_image(game->mlx, HERO_DOWN_6, &w, &h);
	if (!game->sprite_s[6])
		handle_error("xpm error,sprite_s hero 6", game, 0);
	game->sprite_s[7] = mlx_xpm_file_to_image(game->mlx, HERO_DOWN_7, &w, &h);
	if (!game->sprite_s[7])
		handle_error("xpm error,sprite_s hero 7", game, 0);
}

void	import_sprite_d(t_game *game, int w, int h)
{
	game->sprite_d = malloc(sizeof(void *) * 8);
	game->sprite_d[0] = mlx_xpm_file_to_image(game->mlx, HERO_RIGHT_0, &w, &h);
	if (!game->sprite_d[0])
		handle_error("xpm error,sprite_d hero 0", game, 0);
	game->sprite_d[1] = mlx_xpm_file_to_image(game->mlx, HERO_RIGHT_1, &w, &h);
	if (!game->sprite_d[1])
		handle_error("xpm error,sprite_d hero 1", game, 0);
	game->sprite_d[2] = mlx_xpm_file_to_image(game->mlx, HERO_RIGHT_2, &w, &h);
	if (!game->sprite_d[2])
		handle_error("xpm error,sprite_d hero 2", game, 0);
	game->sprite_d[3] = mlx_xpm_file_to_image(game->mlx, HERO_RIGHT_3, &w, &h);
	if (!game->sprite_d[3])
		handle_error("xpm error,sprite_d hero 3", game, 0);
	game->sprite_d[4] = mlx_xpm_file_to_image(game->mlx, HERO_RIGHT_4, &w, &h);
	if (!game->sprite_d[4])
		handle_error("xpm error,sprite_d hero 4", game, 0);
	game->sprite_d[5] = mlx_xpm_file_to_image(game->mlx, HERO_RIGHT_5, &w, &h);
	if (!game->sprite_d[5])
		handle_error("xpm error,sprite_d hero 5", game, 0);
	game->sprite_d[6] = mlx_xpm_file_to_image(game->mlx, HERO_RIGHT_6, &w, &h);
	if (!game->sprite_d[6])
		handle_error("xpm error,sprite_d hero 6", game, 0);
	game->sprite_d[7] = mlx_xpm_file_to_image(game->mlx, HERO_RIGHT_7, &w, &h);
	if (!game->sprite_d[7])
		handle_error("xpm error,sprite_d hero 7", game, 0);
}

void	import_exit_sprite(t_game *game, int w, int h)
{
	game->sprite_exit = malloc(sizeof(void *) * 8);
	game->sprite_exit[0] = mlx_xpm_file_to_image(game->mlx, HERO_EX_1, &w, &h);
	if (!game->sprite_exit[0])
		handle_error("xpm error,sprite exit 0", game, 0);
	game->sprite_exit[1] = mlx_xpm_file_to_image(game->mlx, HERO_EX_2, &w, &h);
	if (!game->sprite_exit[1])
		handle_error("xpm error,sprite exit 1", game, 0);
	game->sprite_exit[2] = mlx_xpm_file_to_image(game->mlx, HERO_EX_3, &w, &h);
	if (!game->sprite_exit[2])
		handle_error("xpm error,sprite exit 2", game, 0);
	game->sprite_exit[3] = mlx_xpm_file_to_image(game->mlx, HERO_EX_4, &w, &h);
	if (!game->sprite_exit[3])
		handle_error("xpm error,sprite exit 3", game, 0);
	game->sprite_exit[4] = mlx_xpm_file_to_image(game->mlx, HERO_EX_5, &w, &h);
	if (!game->sprite_exit[4])
		handle_error("xpm error,sprite exit 4", game, 0);
	game->sprite_exit[5] = mlx_xpm_file_to_image(game->mlx, HERO_EX_6, &w, &h);
	if (!game->sprite_exit[5])
		handle_error("xpm error,sprite exit 5", game, 0);
	game->sprite_exit[6] = mlx_xpm_file_to_image(game->mlx, HERO_EX_7, &w, &h);
	if (!game->sprite_exit[6])
		handle_error("xpm error,sprite exit 6", game, 0);
}
