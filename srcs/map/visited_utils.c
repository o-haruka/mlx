/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:14:04 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 17:01:09 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdlib.h>

// Allocate a 2D array for visited flags
int	**allocate_visited(int rows, int cols)
{
	int	**visited;
	int	i;

	visited = malloc(sizeof(int *) * rows);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		visited[i] = calloc(cols, sizeof(int));
		if (!visited[i])
			return (NULL);
		i++;
	}
	return (visited);
}

// Free the 2D visited array
void	free_visited(int **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
