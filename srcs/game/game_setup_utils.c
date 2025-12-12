/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:30:47 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 17:02:47 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../../includes/so_long.h"
#include "../../libft/stdio/ft_printf/ft_printf.h"
#include <stdlib.h>

// Load the map from file and validate its contents
char	**load_and_validate_map(const char *filename, int *rows)
{
	char	**map;

	map = read_map(filename, rows);
	if (!map)
	{
		ft_printf(RED "マップ読み込み失敗\n" RESET);
		exit(1);
	}
	if (!validate_map(map, *rows))
	{
		ft_printf(RED "Error\nマップが不正です\n" RESET);
		exit(1);
	}
	return (map);
}

// Free the memory allocated for the map
void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// Initialize mlx and exit with cleanup if it fails
void	*init_mlx_or_exit_with_map(char **map, int rows)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		printf(RED "Failed to initialize mlx\n" RESET);
		free_map(map, rows);
		exit(1);
	}
	return (mlx_ptr);
}

// Create a new window and exit if it fails
void	*create_window_or_exit(
	void *mlx_ptr,
	int width,
	int height,
	const char *title)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, width, height, (char *)title);
	if (win_ptr == NULL)
	{
		printf(RED "Failed to create window\n" RESET);
		exit(1);
	}
	return (win_ptr);
}

// Count the number of collectibles in the map
int	count_collectibles_in_map(char **map, int rows)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == COLLECT)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
