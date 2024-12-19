/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:18:29 by mikkayma          #+#    #+#             */
/*   Updated: 2024/12/19 16:06:38 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_location(t_game *game)
{
	int	y;
	int	x;
	int	e;

	x = 0;
	y = 0;
	e = 0;
	game->enemy_x_y = malloc(sizeof(int *) * (game->enemy_c * 4));
	if (game->enemy_x_y == NULL)
		return ;
	while (y < game->map_y - 1)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'X')
			{
				enemy_x_y_import(game, e, x, y);
				e += 4;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	enemy_move_a(t_game *game, int e)
{
	if (game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] - 1] == 'P')
		dead_screen(game);
	if (game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] - 1] == '1'
	|| game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] - 1] == 'C'
	|| game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] - 1] == 'X'
	|| game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] - 1] == 'E')
	{
		game->enemy_x_y[e + 3] = rand() % 4;
		if (game->enemy_x_y[e + 3] == 0)
			enemy_move_a(game, e);	
	}
	if (game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] - 1] == '0')
	{
		game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1]] = '0';
		game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] - 1] = 'X';
		game->enemy_x_y[e + 1]--;
	}
}

void	enemy_move_w(t_game *game, int e)
{
	if (game->map[game->enemy_x_y[e + 2] - 1][game->enemy_x_y[e + 1]] == 'P')
		dead_screen(game);
	if (game->map[game->enemy_x_y[e + 2] - 1][game->enemy_x_y[e + 1]] == '1'
	|| game->map[game->enemy_x_y[e + 2] - 1][game->enemy_x_y[e + 1]] == 'C'
	|| game->map[game->enemy_x_y[e + 2] - 1][game->enemy_x_y[e + 1]] == 'X'
	|| game->map[game->enemy_x_y[e + 2] - 1][game->enemy_x_y[e + 1]] == 'E')
	{
		game->enemy_x_y[e + 3] = rand() % 4;
		if (game->enemy_x_y[e + 3] == 3)
			enemy_move_a(game, e);	
	}
	if (game->map[game->enemy_x_y[e + 2] - 1][game->enemy_x_y[e + 1]] == '0')
	{
		game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1]] = '0';
		game->map[game->enemy_x_y[e + 2] - 1][game->enemy_x_y[e + 1]] = 'X';
		game->enemy_x_y[e + 2]--;
	}
}

void	enemy_move_s(t_game *game, int e)
{
	if (game->map[game->enemy_x_y[e + 2] + 1][game->enemy_x_y[e + 1]] == 'P')
		dead_screen(game);
	if (game->map[game->enemy_x_y[e + 2] + 1][game->enemy_x_y[e + 1]] == '1'
	|| game->map[game->enemy_x_y[e + 2] + 1][game->enemy_x_y[e + 1]] == 'C'
	|| game->map[game->enemy_x_y[e + 2] + 1][game->enemy_x_y[e + 1]] == 'X'
	|| game->map[game->enemy_x_y[e + 2] + 1][game->enemy_x_y[e + 1]] == 'E')
	{
		game->enemy_x_y[e + 3] = rand() % 4;
		if (game->enemy_x_y[e + 3] == 1)
			enemy_move_a(game, e);	
	}
	if (game->map[game->enemy_x_y[e + 2] + 1][game->enemy_x_y[e + 1]] == '0')
	{
		game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1]] = '0';
		game->map[game->enemy_x_y[e + 2] + 1][game->enemy_x_y[e + 1]] = 'X';
		game->enemy_x_y[e + 2]++;
	}
}

void	enemy_move_d(t_game *game, int e)
{
	if (game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] + 1] == 'P')
		dead_screen(game);
	if (game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] + 1] == '1'
	|| game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] + 1] == 'C'
	|| game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] + 1] == 'X'
	|| game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] + 1] == 'E')
	{
		game->enemy_x_y[e + 3] = rand() % 4;
		if (game->enemy_x_y[e + 3] == 2)
			enemy_move_a(game, e);	
	}
	if (game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] + 1] == '0')
	{
		game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1]] = '0';
		game->map[game->enemy_x_y[e + 2]][game->enemy_x_y[e + 1] + 1] = 'X';
		game->enemy_x_y[e + 1]++;
	}
}
