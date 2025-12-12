/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:07:34 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 16:55:40 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdlib.h>

// Flood fill algorithm to mark reachable tiles
static void	flood_fill(t_mapinfo info, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || x >= info.rows || y >= info.cols)
		return ;
	if (info.map[x][y] == '1' || visited[x][y])
		return ;
	visited[x][y] = 1;
	flood_fill(info, x + 1, y, visited);
	flood_fill(info, x - 1, y, visited);
	flood_fill(info, x, y + 1, visited);
	flood_fill(info, x, y - 1, visited);
}

// Find the player's coordinates in the map
static int	find_player_xy(t_mapinfo info, int *px, int *py)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.rows)
	{
		j = 0;
		while (j < info.cols)
		{
			if (info.map[i][j] == PLAYER)
			{
				*px = i;
				*py = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// Check if all collectibles and exit are reachable
static int	check_reachable(t_mapinfo info, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.rows)
	{
		j = 0;
		while (j < info.cols)
		{
			if ((info.map[i][j] == COLLECT || info.map[i][j] == EXIT)
				&& !visited[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Determine if the map is solvable (all items and exit reachable)
int	is_map_solvable(char **map, int rows, int cols)
{
	int			**visited;
	int			px;
	int			py;
	int			result;
	t_mapinfo	info;

	px = -1;
	py = -1;
	result = 1;
	info.map = map;
	info.rows = rows;
	info.cols = cols;
	visited = allocate_visited(rows, cols);
	if (!visited)
		return (0);
	if (!find_player_xy(info, &px, &py))
	{
		free_visited(visited, rows);
		return (0);
	}
	flood_fill(info, px, py, visited);
	result = check_reachable(info, visited);
	free_visited(visited, rows);
	return (result);
}
