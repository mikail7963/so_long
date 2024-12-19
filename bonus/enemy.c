/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:29:32 by mikkayma          #+#    #+#             */
/*   Updated: 2024/12/19 14:42:09 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	import_enemy_way(t_game *game)
{
	int	i;
	int	e;

	i = 0;
	e = game->enemy_c * 4;
	while (i < e - 1)
	{
		if (game->enemy_x_y[i + 3] == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->enemy_left,
				game->enemy_x_y[i + 1] * 32, game->enemy_x_y[i + 2] * 32);
		if (game->enemy_x_y[i + 3] == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->enemy_down,
				game->enemy_x_y[i + 1] * 32, game->enemy_x_y[i + 2] * 32);
		if (game->enemy_x_y[i + 3] == 2)
			mlx_put_image_to_window(game->mlx, game->win, game->enemy_right,
				game->enemy_x_y[i + 1] * 32, game->enemy_x_y[i + 2] * 32);
		if (game->enemy_x_y[i + 3] == 3)
			mlx_put_image_to_window(game->mlx, game->win, game->enemy_up,
				game->enemy_x_y[i + 1] * 32, game->enemy_x_y[i + 2] * 32);
		i += 4;
	}
}

void	import_enemy_assets(t_game *game)
{
	int	w;
	int	h;

	game->enemy_up = mlx_xpm_file_to_image(game->mlx, "assets/enemy/up.xpm",
			&w, &h);
	if (game->enemy_up == NULL)
		handle_error("xpm error enemy up", game, 1);
	game->enemy_down = mlx_xpm_file_to_image(game->mlx, "assets/enemy/down.xpm",
			&w, &h);
	if (game->enemy_down == NULL)
		handle_error("xpm error enemy down", game, 1);
	game->enemy_left = mlx_xpm_file_to_image(game->mlx, "assets/enemy/left.xpm",
			&w, &h);
	if (game->enemy_left == NULL)
		handle_error("xpm error enemy left", game, 1);
	game->enemy_right = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy/right.xpm", &w, &h);
	if (game->enemy_right == NULL)
		handle_error("xpm error enemy right", game, 1);
}

void	enemy_move(t_game *game, int enemy)
{
	if (game->enemy_x_y[enemy + 3] == 0)
		enemy_move_a(game, enemy);
	else if (game->enemy_x_y[enemy + 3] == 1)
		enemy_move_s(game, enemy);
	else if (game->enemy_x_y[enemy + 3] == 2)
		enemy_move_d(game, enemy);
	else if (game->enemy_x_y[enemy + 3] == 3)
		enemy_move_w(game, enemy);
}

void	enemy_x_y_import(t_game *game, int e, int x, int y)
{
	game->enemy_x_y[e] = e;
	game->enemy_x_y[e + 1] = x;
	game->enemy_x_y[e + 2] = y;
	game->enemy_x_y[e + 3] = rand() % 4;
}

int	all_enemy_move(t_game *game)
{
	static int	tick = 0;
	int			e;
	int			i;

	i = 0;
	e = game->enemy_c * 4;
	tick++;
	if (tick >= 10)
	{
		while (i <= e)
		{
			enemy_move(game, i);
			i += 4;
		}
		tick = 0;
	}
	return (0);
}
