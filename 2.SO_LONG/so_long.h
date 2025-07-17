/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:04:37 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 20:35:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"

# define TILE_SIZE 32
# define WINDOW_TITLE "so_long"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define ERR_ARGS "Error: Invalid number of arguments\n"
# define ERR_FILE "Error: Invalid file\n"
# define ERR_MAP "Error: Invalid map\n"
# define ERR_MLX "Error: MLX initialization failed\n"
# define ERR_COMPONENTS "Error: Invalid number of components\n"
# define ERR_CHAR "Error: Invalid character in map\n"
# define ERR_PATH "Error: No valid path exists\n"
# define ERR_RECT "Error: Map is not rectangular\n"
# define ERR_WALLS "Error: Map is not surrounded by walls\n"
# define ERR_FILE_OPEN "Error: Cannot open map file\n"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_player;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	void	*img_floor;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		moves;
}	t_game;

//	GAME_MOVES
void	handle_movement(int keycode, t_game *game);
//	MAP_CHECK
int		check_map(t_game *game);
//	MAP_CHECK2
int		check_components(t_game *game);
int		check_valid_chars(char **map);
//	MAP_PATH
int		check_valid_path(t_game *game);
//	MAP_RENDER
void	render_map(t_game *game);
//	MAP_READ_MAP
char	**read_map(t_game *game, char *filename);
void	load_images(t_game *game);
//	UTILS
void	free_map(char **map);
void	free_images(t_game *game);
void	cleanup_game(t_game *game);
void	error_exit(t_game *game, char *message);
//	WINDOW_HANDLING
int		close_window(t_game *game);
void	init_window(t_game *game);

#endif
