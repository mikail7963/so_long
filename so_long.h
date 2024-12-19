/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:36:18 by mikkayma          #+#    #+#             */
/*   Updated: 2024/12/19 15:09:50 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libs/get_next_line/get_next_line.h"
# include "libs/ft_printf/ft_printf.h"
# define HERO_UP_0 "assets/hero/up/hero_0.xpm"
# define HERO_UP_1 "assets/hero/up/hero_1.xpm"
# define HERO_UP_2 "assets/hero/up/hero_2.xpm"
# define HERO_UP_3 "assets/hero/up/hero_3.xpm"
# define HERO_UP_4 "assets/hero/up/hero_4.xpm"
# define HERO_UP_5 "assets/hero/up/hero_5.xpm"
# define HERO_UP_6 "assets/hero/up/hero_6.xpm"
# define HERO_UP_7 "assets/hero/up/hero_7.xpm"
# define HERO_DOWN_0 "assets/hero/down/hero_0.xpm"
# define HERO_DOWN_1 "assets/hero/down/hero_1.xpm"
# define HERO_DOWN_2 "assets/hero/down/hero_2.xpm"
# define HERO_DOWN_3 "assets/hero/down/hero_3.xpm"
# define HERO_DOWN_4 "assets/hero/down/hero_4.xpm"
# define HERO_DOWN_5 "assets/hero/down/hero_5.xpm"
# define HERO_DOWN_6 "assets/hero/down/hero_6.xpm"
# define HERO_DOWN_7 "assets/hero/down/hero_7.xpm"
# define HERO_LEFT_0 "assets/hero/left/hero_0.xpm"
# define HERO_LEFT_1 "assets/hero/left/hero_1.xpm"
# define HERO_LEFT_2 "assets/hero/left/hero_2.xpm"
# define HERO_LEFT_3 "assets/hero/left/hero_3.xpm"
# define HERO_LEFT_4 "assets/hero/left/hero_4.xpm"
# define HERO_LEFT_5 "assets/hero/left/hero_5.xpm"
# define HERO_LEFT_6 "assets/hero/left/hero_6.xpm"
# define HERO_LEFT_7 "assets/hero/left/hero_7.xpm"
# define HERO_RIGHT_0 "assets/hero/right/hero_0.xpm"
# define HERO_RIGHT_1 "assets/hero/right/hero_1.xpm"
# define HERO_RIGHT_2 "assets/hero/right/hero_2.xpm"
# define HERO_RIGHT_3 "assets/hero/right/hero_3.xpm"
# define HERO_RIGHT_4 "assets/hero/right/hero_4.xpm"
# define HERO_RIGHT_5 "assets/hero/right/hero_5.xpm"
# define HERO_RIGHT_6 "assets/hero/right/hero_6.xpm"
# define HERO_RIGHT_7 "assets/hero/right/hero_7.xpm"
# define HERO_EX_1 "assets/exit/exit_1.xpm"
# define HERO_EX_2 "assets/exit/exit_2.xpm"
# define HERO_EX_3 "assets/exit/exit_3.xpm"
# define HERO_EX_4 "assets/exit/exit_4.xpm"
# define HERO_EX_5 "assets/exit/exit_5.xpm"
# define HERO_EX_6 "assets/exit/exit_6.xpm"
# define HERO_EX_7 "assets/exit/exit_7.xpm"
# define RED "\033[31m"

typedef struct game
{
	void	*wall;
	void	*floor;
	void	*key;
	void	*lock_exit;
	void	*horizontal_wall;
	void	*vertical_wall;
	void	*wall_ld;
	void	*wall_lu;
	void	*wall_rd;
	void	*wall_ru;

	void	**sprite_w;
	void	**sprite_a;
	void	**sprite_s;
	void	**sprite_d;
	void	**sprite_exit;
	int		hero_way;
	int		is_moving;

	void	*enemy_up;
	void	*enemy_down;
	void	*enemy_left;
	void	*enemy_right;
	int		*enemy_x_y;
	int		enemy_way;
	int		enemy_c;

	void	*mlx;
	void	*win;

	int		exit_x;
	int		exit_y;

	int		coin;
	int		player_c;
	int		exit;
	int		error;
	int		map_x;
	int		map_y;
	int		player_x;
	int		player_y;
	int		move;

	char	**map;
	char	**map_clone;
	char	*move_str;
}t_game;

void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	enemy_move_w(t_game *game, int e);
void	enemy_move_a(t_game *game, int e);
void	enemy_move_s(t_game *game, int e);
void	enemy_move_d(t_game *game, int e);
void	import_sprite_w(t_game *game, int w, int h);
void	import_sprite_a(t_game *game, int w, int h);
void	import_sprite_s(t_game *game, int w, int h);
void	import_sprite_d(t_game *game, int w, int h);
void	import_enemy_way(t_game *game);
void	import_enemy_assets(t_game *game);
void	import_exit_sprite(t_game *game, int w, int h);
void	enemy_x_y_import(t_game *game, int e, int x, int y);
void	map(char *folder, t_game *cordinat);
void	map_linecheck(char *folder, t_game *game);
void	objects(char object, t_game *game, int map_c, int p_x);
int		all_enemy_move(t_game *game);
int		key_check(int keycode, t_game *game);
void	wall_check(t_game *game);
int		roadcheck(int x, int y, char **map, t_game *game);
int		mapcheck(t_game *game);
void	map_import_window(t_game *game, int x, int y);
void	assets_import(t_game *game);
void	free_map(t_game *game);
char	**clonemap(t_game *game);
char	**fullmap_import(char *folder, char **fullmap, t_game *game);
void	assets_import(t_game *game);
void	assets_import_wall(t_game *game);
void	enemy_location(t_game *game);
void	enemy_move(t_game *game, int enemy);
char	*ft_itoa(int n);
int		play_sprite_exit(t_game *game, int x, int y);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
void	print_tern(t_game *game);
int		play_sprite_on_move(t_game *game);
int		animation_ticks(int *tick, int speed, int max_frames);
void	free_clone(char **map_clone, int map_y);
int		handle_error(const char *msg, t_game *game, int free_check);
void	play_move_string(t_game *game);
int		close_window(t_game *game);
void	finishscreen(t_game *game);
void	dead_screen(t_game *game);

#endif
