/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikkayma <mikkayma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:16:54 by mikkayma          #+#    #+#             */
/*   Updated: 2024/12/18 17:36:04 by mikkayma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dead_screen(t_game *game)
{
	ft_printf("\033[1;37;41m\n");
	ft_printf("*******************************************************\n");
	ft_printf("*                                                     *\n");
	ft_printf("*                                                     *\n");
	ft_printf("*                  G A M E   O V E R                  *\n");
	ft_printf("*                                                     *\n");
	ft_printf("*                                                     *\n");
	ft_printf("*******************************************************");
	ft_printf("\033[0m\n");
	close_window(game);
}

void	finishscreen(t_game *game)
{
	ft_printf("\033[1;32m");
	ft_printf("*************************************************\n");
	ft_printf("*                                               *\n");
	ft_printf("              * \033[1;33mCONGRATULATIONS\033[1;32m *\n");
	ft_printf("*                                               *\n");
	ft_printf("*     🎉🎉  You did a great job!! 🎉🎉      *\n");
	ft_printf("*                                               *\n");
	ft_printf("*************************************************\n");
	ft_printf("\033[0m");
	close_window(game);
}

int	handle_error(const char *msg, t_game *game, int free_check)
{
	ft_printf("%s%s\033[0m\n", RED, msg);
	if (free_check == 1)
		free_map(game);
	exit (EXIT_FAILURE);
	return (0);
}

void	print_tern(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
		ft_printf("\033[32m%s\033[0m", game->map[i++]);
	ft_printf("\n\033[34mMove %d Coin %d\033[0m\n", game->move, game->coin);
}

int	animation_ticks(int *tick, int speed, int max_frames)
{
	static int	frame = 0;

	if (++(*tick) >= speed)
	{
		*tick = 0;
		if (++frame >= max_frames)
			frame = 0;
	}
	return (frame);
}
