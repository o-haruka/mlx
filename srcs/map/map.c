/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:57:57 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 17:06:55 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/includes/libft.h"
#include "../../libft/stdio/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// Read a single line from the map file and remove the newline character
static char	*read_map_line(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

// Read the map from a file and return it as a 2D array,
// setting the number of rows
char	**read_map(const char *filename, int *rows)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * 1024);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = read_map_line(fd);
	while (line)
	{
		map[i] = line;
		i++;
		line = read_map_line(fd);
	}
	close(fd);
	*rows = i;
	return (map);
}
