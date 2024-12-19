/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:03 by mikkayma          #+#    #+#             */
/*   Updated: 2024/12/19 15:23:21 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	play_sprite_on_move(t_game *game)
{
	static int	tick = 0;
	int			frame;

	if (game->is_moving)
	{
		frame = animation_ticks(&tick, 2, 7);
		if (game->hero_way == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->sprite_w[frame],
				game->player_x * 32, (game->player_y * 32));
		else if (game->hero_way == 2)
			mlx_put_image_to_window(game->mlx, game->win, game->sprite_s[frame],
				game->player_x * 32, (game->player_y * 32));
		else if (game->hero_way == 3)
			mlx_put_image_to_window(game->mlx, game->win, game->sprite_a[frame],
				game->player_x * 32, (game->player_y * 32));
		else if (game->hero_way == 4)
			mlx_put_image_to_window(game->mlx, game->win, game->sprite_d[frame],
				game->player_x * 32, (game->player_y * 32));
		game->is_moving = 0;
	}
	return (0);
}

int	play_sprite_exit(t_game *game, int x, int y)
{
	static int	tick = 0;
	static int	frame = 0;

	if (game->coin > 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->lock_exit, x, y);
		return (0);
	}
	if (frame < 6)
	{
		if (tick >= 10)
		{
			frame = animation_ticks(&tick, 10, 6);
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprite_exit[frame], x, y);
		}
		else
			tick++;
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->sprite_exit[6],
			(x), (y));
	frame++;
	return (0);
}

void	play_move_string(t_game *game)
{
	game->move_str = ft_itoa(game->move);
	mlx_string_put(game->mlx, game->win, 5, game->map_y + 6, 0x000000,
		"move :");
	mlx_string_put(game->mlx, game->win, 50, game->map_y + 6, 0x000000,
		game->move_str);
	free(game->move_str);
}
