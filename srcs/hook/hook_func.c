/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:21:32 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 17:02:20 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/stdio/ft_printf/ft_printf.h"
#include "mlx.h"
#include <stdlib.h>

// Handle key press events for player movement and actions
int	key_hook(int keycode, void *param)
{
	t_game	*game;
	t_move	mv;

	game = (t_game *)param;
	if (!find_player(game->map, game->rows, &mv.px, &mv.py))
		return (0);
	get_move_dir(keycode, &mv);
	if (keycode == ESC)
		exit(0);
	if (mv.dx == 0 && mv.dy == 0)
		return (0);
	mv.nx = mv.px + mv.dx;
	mv.ny = mv.py + mv.dy;
	if (!can_move(game->map, mv.nx, mv.ny))
		return (0);
	if (try_exit(game, mv.nx, mv.ny))
		return (0);
	do_move(game, mv);
	return (0);
}

// Handle window close event and free all resources
int	destroy_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_printf("ウィンドウが閉じられました\n");
	mlx_destroy_image(game->mlx_ptr, game->imgs.player);
	mlx_destroy_image(game->mlx_ptr, game->imgs.wall);
	mlx_destroy_image(game->mlx_ptr, game->imgs.floor);
	mlx_destroy_image(game->mlx_ptr, game->imgs.collect);
	mlx_destroy_image(game->mlx_ptr, game->imgs.exit);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_game_map(game->map, game->rows);
	exit(0);
	return (0);
}
