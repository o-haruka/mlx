/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:12:31 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 17:18:50 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/stdio/ft_printf/ft_printf.h"
#include "mlx.h"
#include <stdlib.h>

// Check if the player can move to the next position
int	can_move(char **map, int nx, int ny)
{
	return (map[ny][nx] != WALL);
}

// Perform the player move and update the game state
void	do_move(t_game *game, t_move mv)
{
	if (game->map[mv.ny][mv.nx] == COLLECT)
	{
		game->collected++;
		ft_printf(CHECK "Collected an item! (%d/%d)\n", game->collected,
			game->collect_count);
	}
	game->map[mv.py][mv.px] = EMPTY;
	game->map[mv.ny][mv.nx] = PLAYER;
	game->move_count++;
	ft_printf("Move count: %d\n", game->move_count);
	draw_map(game->mlx_ptr, game->win_ptr, game);
}

// Try to exit the game if the player is on the exit tile
int	try_exit(t_game *game, int nx, int ny)
{
	if (game->map[ny][nx] == EXIT)
	{
		if (game->collected < game->collect_count)
		{
			ft_printf(CROSS "Items remain!\n");
			return (1);
		}
		ft_printf(GREEN"\n==============================\n"
				   "     ★☆★☆  GOAL!!  ★☆★☆      "
				   "\n==============================\n"RESET);
		exit(0);
	}
	return (0);
}

// Get the movement direction from the keycode
void	get_move_dir(int keycode, t_move *mv)
{
	mv->dx = 0;
	mv->dy = 0;
	if (keycode == W)
		mv->dy = -1;
	else if (keycode == S)
		mv->dy = 1;
	else if (keycode == A)
		mv->dx = -1;
	else if (keycode == D)
		mv->dx = 1;
}

// Free the memory allocated for the game map
void	free_game_map(char **map, int rows)
{
	int	j;

	j = 0;
	while (j < rows)
	{
		free(map[j]);
		j++;
	}
	free(map);
}
