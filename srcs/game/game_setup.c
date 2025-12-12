/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:33:45 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 17:03:15 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/includes/libft.h"
#include "../../libft/stdio/ft_printf/ft_printf.h"
#include <stdlib.h>

// Validate command line arguments for the program
int	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf(RED "Error\nUsage: %s <path to map.ber>\n" RESET, argv[0]);
		return (0);
	}
	return (1);
}

// Set up the game structure and initialize all resources
t_game	setup_game(char **argv)
{
	t_game	game;

	game.map = load_and_validate_map(argv[1], &game.rows);
	game.mlx_ptr = init_mlx_or_exit_with_map(game.map, game.rows);
	init_images(game.mlx_ptr, &game.imgs);
	game.win_ptr = create_window_or_exit(
			game.mlx_ptr,
			game.imgs.width * ft_strlen(game.map[0]),
			game.imgs.height * game.rows,
			"so_long");
	game.collect_count = count_collectibles_in_map(game.map, game.rows);
	game.collected = 0;
	game.move_count = 0;
	return (game);
}
