/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:19:50 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 16:21:44 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../libft/stdio/ft_printf/ft_printf.h"
#include "../libft/stdio/get_next_line/get_next_line.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!validate_args(argc, argv))
		return (1);
	game = setup_game(argv);
	draw_map(game.mlx_ptr, game.win_ptr, &game);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_hook(game.win_ptr, ON_DESTROY, 0, destroy_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
