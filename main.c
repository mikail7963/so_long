/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:36:22 by mikkayma          #+#    #+#             */
/*   Updated: 2025/02/23 17:05:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprite(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(game->mlx, game->sprite_w[i]);
		mlx_destroy_image(game->mlx, game->sprite_a[i]);
		mlx_destroy_image(game->mlx, game->sprite_s[i]);
		mlx_destroy_image(game->mlx, game->sprite_d[i]);
		if (i < 7)
			mlx_destroy_image(game->mlx, game->sprite_exit[i]);
		i++;
	}
}

void	free_image(t_game *game)
{
	free_sprite(game);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->key);
	mlx_destroy_image(game->mlx, game->lock_exit);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->wall_ld);
	mlx_destroy_image(game->mlx, game->wall_lu);
	mlx_destroy_image(game->mlx, game->wall_rd);
	mlx_destroy_image(game->mlx, game->wall_ru);
	mlx_destroy_image(game->mlx, game->vertical_wall);
	mlx_destroy_image(game->mlx, game->horizontal_wall);
	mlx_destroy_image(game->mlx, game->enemy_up);
	mlx_destroy_image(game->mlx, game->enemy_down);
	mlx_destroy_image(game->mlx, game->enemy_left);
	mlx_destroy_image(game->mlx, game->enemy_right);
	free(game->sprite_w);
	free(game->sprite_a);
	free(game->sprite_s);
	free(game->sprite_d);
	free(game->sprite_exit);
	if (game->enemy_c > 0)
		free(game->enemy_x_y);
}

int	close_window(t_game *game)
{
	free_image(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	free(game);
	exit (0);
}

int	game_loop(t_game *game)
{
	if (game->enemy_c > 0)
		all_enemy_move(game);
	play_sprite_on_move(game);
	map_import_window(game, 0, 0);
	play_move_string(game);
	usleep(16666);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		handle_error("Failed to allocate memory.\n", game, 0);
	game->player_c = 0;
	if (ac == 2)
		map(av[1], game);
	else
		handle_error("Wrong argument, please select map.", game, 0);
	mapcheck(game);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		handle_error("Failed to initialize MinilibX.\n", game, 1);
	game->win = mlx_new_window(game->mlx, (game->map_x * 32),
			(game->map_y * 32), "So Long");
	if (game->win == NULL)
		handle_error("failed to create window", game, 1);
	assets_import(game);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite_w[0],
		game->player_x * 32, (game->player_y * 32));
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, 2, 1L << 0, key_check, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
