/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:02:01 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 16:53:57 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/includes/libft.h"

// Check if the map is rectangular and return its width and height
int	is_rectangular(char **map, int *width, int *height)
{
	int		i;
	int		len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	*width = len;
	*height = i;
	return (1);
}

// Check if the map is surrounded by walls ('1')
int	is_surrounded_by_walls(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Check if the map is rectangular and surrounded by walls
static int	check_rectangular_and_walls(char **map, int rows, int *cols)
{
	int	width;
	int	height;

	if (!is_rectangular(map, &width, &height))
		return (0);
	*cols = width;
	if (!is_surrounded_by_walls(map, rows, *cols))
		return (0);
	return (1);
}

// Check if the map has required elements and is solvable
static int	check_elements_and_solvable(char **map, int rows, int cols)
{
	if (!has_required_elements(map, rows, cols))
		return (0);
	if (!is_map_solvable(map, rows, cols))
		return (0);
	return (1);
}

// Validate the map by checking shape, walls, elements, and solvability
int	validate_map(char **map, int rows)
{
	int	cols;

	if (rows == 0 || !map)
		return (0);
	if (!check_rectangular_and_walls(map, rows, &cols))
		return (0);
	if (!check_elements_and_solvable(map, rows, cols))
		return (0);
	return (1);
}
