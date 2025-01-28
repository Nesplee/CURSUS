/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:04:37 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 23:02:42 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define ERR_IMG "Error loading images\n"

# define VALID_CHARS "01CEPN"
# define ENEMY_CHAR 'N'

# define MAX_FRAMES 4
# define FRAME_DELAY 10000

# define DIR_IDLE 0
# define DIR_RIGHT 1
# define DIR_LEFT 2
# define PLAYER_DIR_UP 3
# define PLAYER_DIR_DOWN 4

# define HUD_MOVES_Y 10
# define HUD_COLLECT_Y 30
# define HUD_X 10
# define HUD_COLOR 0xFFFFFF

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	void	*img_floor;
	void	*player_sprites[MAX_FRAMES];
	void	*player_left_sprites[MAX_FRAMES];
	void	*collectible_sprites[4];
	void	*enemy_sprites[4];
	int		enemy_frame;
	int		collectible_frame;
	int		current_frame;
	int		frame_delay;
	int		direction;
	int		is_moving;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	int		collected;
	int		game_over;
	int		enemy_count;
	char	*move_str;
	void	*hud_background;
}	t_game;

//	GAME_HOOK
int		key_hook(int keycode, t_game *game);
void	set_direction(int keycode, t_game *game);
int		animation_loop(t_game *game);
//	GAME_MOVES
void	handle_movement(int keycode, t_game *game);
//	MAP_CHECK
void	load_images(t_game *game);
int		check_map(t_game *game);
//	MAP_CHECK2
int		check_rectangular(char **map);
int		check_walls(char **map);
int		check_components(t_game *game);
int		check_valid_chars(char **map);
//	MAP_LOAD
void	load_base_images(t_game *game);
void	load_player_sprites(t_game *game);
void	load_player_left_sprites(t_game *game);
void	load_collectible_sprites(t_game *game);
void	load_enemy_sprites(t_game *game);
//	MAP_PATH
int		check_valid_path(t_game *game);
//	MAP_RENDER
void	render_floor(t_game *game);
void	render_walls(t_game *game);
void	render_player(t_game *game);
void	render_collectibles(t_game *game);
void	render_exit(t_game *game);
//	MAP_RENDER2
void	render_hud(t_game *game);
void	render_enemies(t_game *game);
//	MAP_READ_MAP
char	**read_map(t_game *game, char *filename);
void	render_map(t_game *game);
//	UTILS
void	cleanup_game(t_game *game);
void	error_exit(t_game *game, char *message);
void	free_map(char **map);
//	UTILS_FREE
void	free_images(t_game *game);
//	WINDOW_HANDLING
int		close_window(t_game *game);
void	init_window(t_game *game);

#endif
