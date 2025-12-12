/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:22:26 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 17:06:13 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/includes/libft.h"

// Count the number of player, exit, and collect elements in the map
static void	count_elements(char **map, int rows, int cols, t_elemcount *cnt)
{
	int	i;
	int	j;

	cnt->player = 0;
	cnt->exit = 0;
	cnt->collect = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == PLAYER)
				cnt->player++;
			if (map[i][j] == EXIT)
				cnt->exit++;
			if (map[i][j] == COLLECT)
				cnt->collect++;
			j++;
		}
		i++;
	}
}

// Check if the map has the required elements:
// 1 player, at least 1 exit and 1 collect
int	has_required_elements(char **map, int rows, int cols)
{
	t_elemcount	cnt;

	count_elements(map, rows, cols, &cnt);
	if (cnt.player != 1 || cnt.exit < 1 || cnt.collect < 1)
		return (0);
	return (1);
}
