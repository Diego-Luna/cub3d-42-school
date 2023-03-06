/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   cub3d.h                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/23 08:28:14 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/06 15:10:08 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define EXTENSION ".cub"

# define NO_D 0
# define D_NO 1
# define D_SO 2
# define D_WE 3
# define D_EA 4

# define WIDTH 512
# define HEIGHT 512
# define TEX_WIDTH 64  // must be power of two
# define TEX_HEIGHT 64 // must be power of two
# define NUM_SPRITES 19

typedef struct s_double_po
{
	double		x;
	double		y;
}				t_double_po;

typedef struct s_int_po
{
	int			x;
	int			y;
}				t_int_po;

typedef struct s_map
{
	char		**map;
	int			w_map;
	int			h_map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*floor;
	uint32_t	floor_color;
	char		*ceilling;
	uint32_t	ceilling_color;
}				t_map;

typedef struct s_player
{
	double		position_x;
	double		position_y;
	int			direction;
	int			angle;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_ray
{
	t_double_po	pos;
	t_double_po	d_side;
	t_double_po	d_delta;

	t_double_po	v;
	t_int_po	w;
	t_int_po	text;
	t_double_po	t_pos;
	t_double_po	raydir;
	t_double_po	dir;

	t_int_po	map;
	t_int_po	step;
	t_int_po	draw;

	double		camerax;
	int			side;
	int			mouse_y;

	bool		hit;
}				t_ray;

typedef struct s_raytace
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			color;
}				t_rayrace;

typedef struct s_state
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*no;
	t_map		map;
	t_player	player;
	t_rayrace	rayrace;
	int			ticks;
	int			last_click_ticks;
	t_ray		ray;
}				t_state;

# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define PRECISION 1500

/*		utils		*/
/*		gnl			*/
//	gnl.c
char			*ft_gnl(int fd);
char			*ft_strdup(char *s1, char *s2);
int				ft_strlen(char *str);

//	pasring.c
uint32_t		ft_atoul(char *str);
bool			ft_complexfile(char *file, int i, t_state *state);
bool			ft_checkfile(char *file, t_state *state);
bool			ft_strchr(char *s1, char *s2);

// start_state
void			ft_start_state(t_state *state);
void			ft_save_map(t_state *state, char *file);

// valid map
bool			ft_valid_map(t_state *state);

// Error
void			ft_error(t_state *state, char *msg);
void			ft_only_error(char *msg);

// utils map
void			ft_run_map_xy(t_state *state, void (*f)(t_state *, char, int,
						int));

// Player
void			ft_player_start(t_state *state);

// utils
void			*ft_calloc(size_t size, size_t type);
char			*ft_free(char *src);
char			*ft_newstr(char *str);
void			ft_free_all(t_state *state);
char			*ft_parsepath(char *file);

//validate.c
void			ft_check_everything(t_state *state, char **av);

// ft_routine
void			ft_routine(void *param);

void			ft_error_print(char *msg);

#endif
