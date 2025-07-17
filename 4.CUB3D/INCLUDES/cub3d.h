/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:26:25 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 14:12:04 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923
# endif

/* ========================================================================= */
/* 							LIBRARIES										 */
/* ========================================================================= */

# include "../LIBFT/libft.h"
# include "../MINILIBX-LINUX/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <fcntl.h>
# include <sys/time.h>
# include <signal.h>

/* ========================================================================= */
/* 						DIMENSIONS FENETRE									 */
/* ========================================================================= */

# define WIN_WIDTH	1280
# define WIN_HEIGHT	720
# define MINIMAP_SCALE 8

/* ========================================================================= */
/* 						FRAMES ANIMATION									 */
/* ========================================================================= */

# define ANIM_FRAMES 5
# define ANIM_DELAY_MS 200
# define COLLISION_OFFSET 0.1
# define FPS_SAMPLES 60
# define CROSSHAIR_SIZE  8
# define CROSSHAIR_COLOR 0xFFFFFF

/* ========================================================================= */
/* 							CODES CLAVIERS									 */
/* ========================================================================= */

# define KEY_ESC	65307
# define KEY_W		119	// KEY_Z -> 122
# define KEY_A		97	// KEY_Q -> 113
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_SPACE	32
# define KEY_E		101
# define KEY_SHIFT	65505

/* ========================================================================= */
/* 							STRUCTURES										 */
/* ========================================================================= */

/* ======================== STRUCTURE GESTION IMAGE ======================== */

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_img;

/* ======================= STRUCTURE GESTION TEXTURE ======================= */

typedef struct s_texture
{
	t_img		img;
	char		*path;
}		t_texture;

/* ======================= STRUCTURE GESTION JOUEUR ======================== */

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
	double	move_speed;
	double	rot_speed;
}		t_player;

/* ======================== STRUCTURE GESTION MAP ========================== */

typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
}		t_map;

/* ======================= STRUCTURE GESTION PORTE ========================= */

typedef struct s_door
{
	int			x;
	int			y;
	int			open;
	t_texture	anim[2];
}		t_door;

/* ====================== STRUCTURE GESTION SPRITE ========================= */

typedef struct s_sprite
{
	double	x;
	double	y;
	int		frame;
	int		num_frames;
	t_img	*frames;
}		t_sprite;

/* ======================= STRUCTURE GESTION MLX =========================== */

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_mlx;

/* ====================== STRUCTURE GESTION INPUT ========================== */

typedef struct s_input
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
	int		key_space;
	int		key_e;
	int		key_shift;
	int		key_escape;
}		t_input;

/* ============== STRUCTURE GESTION RAYCASTNG PAR COLONNE ================== */

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	perp_wall_dist;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	tex_step;
	double	tex_pos;
}		t_ray;

/* ==================== STRUCTURE GESTION RAYCASTNG ======================== */

typedef struct s_raycast_config
{
	double	fov;
	double	plane_x;
	double	plane_y;
}		t_raycast_config;

/* ==================== STRUCTURE GESTION ANIMATION ======================== */

typedef struct s_anim
{
	t_texture	frames[ANIM_FRAMES];
	int			current;
	double		timer;
}		t_anim;

/* ======================= STRUCTURE GESTION JEU =========================== */

typedef struct s_game
{
	t_mlx				mlx;
	t_img				frame;
	t_player			player;
	t_map				map;
	t_texture			text_north;
	t_texture			text_south;
	t_texture			text_east;
	t_texture			text_west;
	int					f_color;
	int					c_color;
	t_door				*doors;
	int					nb_doors;
	t_sprite			*sprites;
	int					nb_sprites;
	t_input				input;
	t_raycast_config	raycast_cfg;
	t_ray				*ray_array;
	t_anim				anim_north;
	t_anim				anim_south;
	t_anim				anim_east;
	t_anim				anim_west;
	double				time;
	double				old_time;
}		t_game;

/* ========================= 1. INITIALISATION ============================ */
//		INITIALISATION_ANIMATION
void					init_animations(t_game *g);
//		INITIALISATION_DOORS
void					init_doors(t_game *g);
void					init_doors_images(t_game *g);
//		INITIALISATION_HOOKS
int						close_window(t_game *g);
void					init_hooks(t_game *g);
//		INITIALISATION_KEYS
int						key_press(int key, t_game *g);
int						key_release(int key, t_game *g);
void					init_input(t_input *input);
//		INITIALISATION_MAP
void					init_map(t_map *map, char **lines, int nb_lines,
							int max_width);
void					init_frame(t_img *frame, void *mlx_ptr);
void					init_texture(t_texture *tex, char *path, t_mlx *mlx);
//		INITIALISATION_MLX
void					init_mlx(t_mlx *mlx);
void					init_game(t_game *g);
//		INITIALISATION_PLAYER
void					set_player_spawn(t_game *g);
void					init_player(t_game *g);
//		INITIALISATION_RAYCASTING
void					init_ray_array(t_game *game);
void					init_raycast_config(t_raycast_config *raycast_cfg);

/* ============================ 2.LEXING ================================ */
//		READ_DIRECTIVES
int						read_next_directive(int fd, t_game *g,
							char **first_map_line);
//		READ_MAP_CONTENT
char					**collect_map_body(int fd, int *nb_lines,
							int *max_width);
//		READ_MAP
char					**read_map_line(int fd, int *nb_lines,
							int *max_width, char *first_line);

/* ============================= 3.CHECKING ================================ */
//		CHECK_CONFIG
void					check_config(t_game *game, const char *filename);
//		CHECK_FILE
void					check_map(t_map *map, const char *filename);
//		CHECK_MAP_CLOSED
void					check_map_closed(const char *filename, t_map *map);

/* ============================= 4.PARSING ================================ */
//		PARSE_TEXTURES
int						is_texture_id(char *id);
void					parse_texture(char *id, char *path, t_game *g);
//		PARSE_COLORS
void					parse_color(char id, char *vals, t_game *g);
//		PARSE_MAP
void					parse_cub(const char *file, t_game *g);

/* ============================= 5.UPDATE ================================ */
//		UPDATE_ANIMATIONS
int						is_wall(t_game *g, double x, double y);
void					update_animations(t_game *g, double delta);
//		UPDATE_MOVE
void					try_move(t_game *g, double nx, double ny);
//		UPDATE_PLAYER_MOVEMENT
void					update_player_movement(t_game *g, double speed);
//		UPDATE_PLAYER
void					update_player(t_game *g, double delta);

/* ======================= 6. RENDERING ======================= */
//		DRAW_CROSSHAIR
void					draw_crosshair(t_game *g);
//		DRAW_DOOR
int						door_index(t_game *g, int mx, int my);
void					try_toggle_door(t_game *g);
//		DRAW_FPS
void					draw_fps_ui(t_game *g, double delta);
//		DRAW_MINIMAP
void					draw_minimap(t_game *g);
//		DRAW_WALLS
void					draw_wall(t_game *g, int x, t_ray *r);
//		GAME_LOOP
double					get_time(void);
int						game_loop(void *param);
//		PERFORM_DDA
void					perform_dda(t_game *g, t_ray *r);
//		RAYCASTING
void					cast_ray(t_game *g, int x);
//		RENDER_ALL
void					render_all(t_game *g, double delta);

/* ============================= 9. UTILS ================================= */
//		ERROR
void					exit_error(const char *msg);
void					color_error(char **parts, char *trim);
int						close_window(t_game *g);
void					cleanup(int status, void *arg);
//		FREE_GAME
void					free_frame(t_img *frame, void *mlx_ptr);
void					free_rays(t_game *g);
void					free_tab(char **tab);
void					free_map(t_map *map);
void					free_game(t_game *g);
//		FREE_IMAGES
void					free_textures(t_game *g);
void					free_doors(t_game *g);
void					free_sprites(t_game *g);
void					free_animations(t_game *g);

#endif
