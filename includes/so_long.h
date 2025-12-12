/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:35:55 by homura            #+#    #+#             */
/*   Updated: 2025/12/12 16:49:25 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define CHECK "\033[32m[✔]\033[0m"
# define CROSS "\033[31m[✘]\033[0m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

enum		e_map_element
{
	EMPTY = '0',
	WALL = '1',
	COLLECT = 'C',
	EXIT = 'E',
	PLAYER = 'P'
};

enum		e_events_func
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum		e_keycodes
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100
};

/*
** Structure for image set (player, wall, floor, collect, exit)
*/
typedef struct s_img_set
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit;
	int		width;
	int		height;
}	t_img_set;

/*
** Structure for tile information (mlx, win, images, x, y, tile type)
*/
typedef struct s_tileinfo
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_set	*imgs;
	int			x;
	int			y;
	char		tile;
}	t_tileinfo;

/*
** Structure for move information (player and next positions, delta)
*/
typedef struct s_move
{
	int	px;
	int	py;
	int	nx;
	int	ny;
	int	dx;
	int	dy;
}	t_move;

/*
** Structure for game state (mlx, win, map, images, counts)
*/
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			rows;
	t_img_set	imgs;
	int			collect_count;
	int			collected;
	int			move_count;
}	t_game;

/*
** Structure for map information (map, rows, cols)
*/
typedef struct s_mapinfo
{
	char	**map;
	int		rows;
	int		cols;
}	t_mapinfo;

/*
** Structure for element count (player, exit, collect)
*/
typedef struct s_elemcount
{
	int	player;
	int	exit;
	int	collect;
}	t_elemcount;

// hook events
int		key_hook(int keycode, void *param);
int		destroy_hook(void *param);

// map
char	**read_map(const char *filename, int *rows);
int		is_rectangular(char **map, int *width, int *height);
int		is_surrounded_by_walls(char **map, int rows, int cols);
int		validate_map(char **map, int rows);
int		is_map_solvable(char **map, int rows, int cols);
int		has_required_elements(char **map, int rows, int cols);
int		**allocate_visited(int rows, int cols);
void	free_visited(int **visited, int rows);

// drawing & images
void	draw_map(void *mlx_ptr, void *win_ptr, t_game *game);
void	init_images(void *mlx_ptr, t_img_set *imgs);

// game setup & utils
int		find_player(char **map, int rows, int *px, int *py);
int		count_collectibles(char **map, int rows);
int		validate_args(int argc, char **argv);
t_game	setup_game(char **argv);
char	**load_and_validate_map(const char *filename, int *rows);
void	*init_mlx_or_exit(void);
void	*create_window_or_exit(
			void *mlx_ptr,
			int width,
			int height,
			const char *title);
int		count_collectibles_in_map(char **map, int rows);
void	*init_mlx_or_exit_with_map(char **map, int rows);
void	get_move_dir(int keycode, t_move *mv);
int		can_move(char **map, int nx, int ny);
int		try_exit(t_game *game, int nx, int ny);
void	do_move(t_game *game, t_move mv);

// free
void	free_images(void *mlx_ptr, t_img_set *imgs);
void	free_map(char **map, int rows);
void	free_game_map(char **map, int rows);

#endif