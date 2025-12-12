/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:29:34 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 17:03:36 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Find the player's position in the map and store it in px, py
int	find_player(char **map, int rows, int *px, int *py)
{
	int	x;
	int	y;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == PLAYER)
			{
				*px = x;
				*py = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

// Count the number of collectibles in the map
int	count_collectibles(char **map, int rows)
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
