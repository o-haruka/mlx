/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:15:43 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 16:54:55 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

// Draw a single tile based on its type
static void	draw_tile(t_tileinfo info)
{
	mlx_put_image_to_window(
		info.mlx_ptr, info.win_ptr, info.imgs->floor,
		info.x * info.imgs->width, info.y * info.imgs->height);
	if (info.tile == PLAYER)
		mlx_put_image_to_window(
			info.mlx_ptr, info.win_ptr, info.imgs->player,
			info.x * info.imgs->width, info.y * info.imgs->height);
	else if (info.tile == WALL)
		mlx_put_image_to_window(
			info.mlx_ptr, info.win_ptr, info.imgs->wall,
			info.x * info.imgs->width, info.y * info.imgs->height);
	else if (info.tile == COLLECT)
		mlx_put_image_to_window(
			info.mlx_ptr, info.win_ptr, info.imgs->collect,
			info.x * info.imgs->width, info.y * info.imgs->height);
	else if (info.tile == EXIT)
		mlx_put_image_to_window(
			info.mlx_ptr, info.win_ptr, info.imgs->exit,
			info.x * info.imgs->width, info.y * info.imgs->height);
}

// Draw the entire map using the image set
void	draw_map(void *mlx_ptr, void *win_ptr, t_game *game)
{
	int			row;
	int			col;
	char		**map;
	t_tileinfo	info;

	map = game->map;
	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (map[row][col])
		{
			info.mlx_ptr = mlx_ptr;
			info.win_ptr = win_ptr;
			info.imgs = &game->imgs;
			info.x = col;
			info.y = row;
			info.tile = map[row][col];
			draw_tile(info);
			col++;
		}
		row++;
	}
}

// Free all loaded images
void	free_images(void *mlx_ptr, t_img_set *imgs)
{
	if (imgs->player)
		mlx_destroy_image(mlx_ptr, imgs->player);
	if (imgs->wall)
		mlx_destroy_image(mlx_ptr, imgs->wall);
	if (imgs->floor)
		mlx_destroy_image(mlx_ptr, imgs->floor);
	if (imgs->collect)
		mlx_destroy_image(mlx_ptr, imgs->collect);
	if (imgs->exit)
		mlx_destroy_image(mlx_ptr, imgs->exit);
}

// Initialize all images from XPM files
void	init_images(void *mlx_ptr, t_img_set *imgs)
{
	imgs->player = mlx_xpm_file_to_image(
			mlx_ptr, "images/player.xpm", &imgs->width, &imgs->height);
	imgs->wall = mlx_xpm_file_to_image(
			mlx_ptr, "images/wall.xpm", &imgs->width, &imgs->height);
	imgs->floor = mlx_xpm_file_to_image(
			mlx_ptr, "images/floor.xpm", &imgs->width, &imgs->height);
	imgs->collect = mlx_xpm_file_to_image(
			mlx_ptr, "images/collect.xpm", &imgs->width, &imgs->height);
	imgs->exit = mlx_xpm_file_to_image(
			mlx_ptr, "images/exit.xpm", &imgs->width, &imgs->height);
	if (!imgs->player || !imgs->wall || !imgs->floor
		|| !imgs->collect || !imgs->exit)
	{
		printf(RED "Failed to load one or more images\n" RESET);
		free_images(mlx_ptr, imgs);
		exit(1);
	}
}
