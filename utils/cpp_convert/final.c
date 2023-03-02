/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   final.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/01 10:29:46 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/01 10:42:15 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// define window size
#define WIDTH 640
#define HEIGHT 480

// structure definition for raycasting
typedef struct s_ray
{
	double posX;   // player position x
	double posY;   // player position y
	double dirX;   // vector direction x
	double dirY;   // vector direction y
	double planeX; // 2d raycaster version of camera plane x
	double planeY; // 2d raycaster version of camera plane y
	double time;   // time of current frame
}		t_ray;

// structure definition for mlx
typedef struct s_mlx
{
	void *mlx; // mlx pointer
	void *win; // window pointer

}		t_mlx;

// structure definition data
typedef struct s_data
{
	t_mlx mlx; // mlx structure
	t_ray ray; // ray structure
}		t_data;

int32_t	main(void)
{
	t_data data;

	data.mlx.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!data.mlx.mlx)
		return (1);
	mlx_loop(data.mlx.mlx);
	mlx_terminate(data.mlx.mlx);
	return (0);
}