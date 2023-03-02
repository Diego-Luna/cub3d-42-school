/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   ray_converted.c                                ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/28 13:46:10 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/01 13:19:17 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define WIDTH 640
#define HEIGHT 480

typedef struct ray_converted
{
	double posX;         // player position x
	double posY;         // player position y
	double dirX;         // vector direction x
	double dirY;         // vector direction y
	double planeX;       // 2d raycaster version of camera plane x
	double planeY;       // 2d raycaster version of camera plane y
	double cameraX;      // camera position
	double rayDirX;      // ray direction x
	double rayDirY;      // ray direction y
	int mapX;            // map position x
	int mapY;            // map position y
	double deltaDistX;   // length of ray from one x side to next x
	double deltaDistY;   // length of ray from one y side to next y
	int hit;             // was there a wall hit?
	int stepX;           // what direction to step in direction (either +1or-1)
	int stepY;           // what direction to step y direction (either +1or-1)
	double sideDistX;    // length of ray from current position to next x side
	double sideDistY;    // length of ray from current position to next y side
	int side;            // was a NS or a EW wall hit?
	double frameTime;    // time of current frame
	double moveSpeed;    // the constant value is in squares/second - 5?
	double rotSpeed;     // the constant value is in radians/second - 3?
	double perpWallDist; // perpendicular distance from camera to wall
	int lineHeight;      // height of line to draw on screen
	t_map map;           // map structure
}		ray_converted;

void	ft_movement(ray_converted *ray)
{
	mlx_t	mlx;

	// forward is pressed
	if (mlx_is_key_down(&mlx, MLX_KEY_UP))
	{
		// move forward if no wall in front of you
		if (ray->map.map[(int)(ray->posX + ray->dirX
				* ray->moveSpeed)][(int)(ray->posY)] == 0)
			ray->posX += ray->dirX * ray->moveSpeed;
		if (ray->map.map[(int)(ray->posX)][(int)(ray->posY + ray->dirY
				* ray->moveSpeed)] == 0)
			ray->posY += ray->dirY * ray->moveSpeed;
	}
	// backward is pressed
	if (mlx_is_mouse_down(&mlx, MLX_KEY_DOWN))
	{
		// move backward if no wall behind you
		if (ray->map.map[(int)(ray->posX - ray->dirX
				* ray->moveSpeed)][(int)(ray->posY)] == 0)
			ray->posX -= ray->dirX * ray->moveSpeed;
		if (ray->map.map[(int)(ray->posX)][(int)(ray->posY - ray->dirY
				* ray->moveSpeed)] == 0)
			ray->posY -= ray->dirY * ray->moveSpeed;
	}
	// right is pressed
	if (mlx_is_key_down(&mlx, MLX_KEY_RIGHT))
	{
		// move right if no wall right of you
		if (ray->map.map[(int)(ray->posX + ray->dirY
				* ray->moveSpeed)][(int)(ray->posY)] == 0)
			ray->posX += ray->dirY * ray->moveSpeed;
		if (ray->map.map[(int)(ray->posX)][(int)(ray->posY - ray->dirX
				* ray->moveSpeed)] == 0)
			ray->posY -= ray->dirX * ray->moveSpeed;
	}
	// left is pressed
	if (mlx_is_key_down(&mlx, MLX_KEY_LEFT))
	{
		// move left if no wall left of you
		if (ray->map.map[(int)(ray->posX - ray->dirY
				* ray->moveSpeed)][(int)(ray->posY)] == 0)
			ray->posX -= ray->dirY * ray->moveSpeed;
		if (ray->map.map[(int)(ray->posX)][(int)(ray->posY + ray->dirX
				* ray->moveSpeed)] == 0)
			ray->posY += ray->dirX * ray->moveSpeed;
	}
}

void	ft_calculate_ray_position_direction(ray_converted *ray)
{
	int	x;

	x = 0;
	// Calculate ray position and direction
	// x-coordinate in camera space
	while (x < WIDTH)
	{
		// x-coordinate in camera space
		ray->cameraX = 2 * x / (double)WIDTH - 1;
		// x-coordinate in camera space
		ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
		ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
		// Which box of the map we're in according to the player position
		ray->mapX = (int)ray->posX;
		ray->mapY = (int)ray->posY;
		// Length of ray from current position to next x or y-side
		ray->deltaDistX = abs(1 / ray->rayDirX);
		ray->deltaDistY = abs(1 / ray->rayDirY);
		// was there a wall hit?
		ray->hit = 0;
		// Calculate step and initial sideDist
		if (ray->rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
		}
		if (ray->rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
		}
		// Perform DDA
		while (ray->hit == 0)
		{
			// Jump to next map square, OR in x-direction, OR in y-direction
			if (ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->deltaDistX;
				ray->mapX += ray->stepX;
				ray->side = 0;
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				ray->mapY += ray->stepY;
				ray->side = 1;
			}
			// Check if ray has hit a wall
			if (ray->map.map[ray->mapX][ray->mapY] > '1')
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->perpWallDist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2)
				/ ray->rayDirX;
		else
			ray->perpWallDist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2)
				/ ray->rayDirY;
		ray->moveSpeed = 5;
		ray->rotSpeed = 0.05;
		x++;
	}
}

void	ft_func(void)
{
	ray_converted ray;

	// Initialize raycasting variables
	// x-coordinate of the player as double
	ray.posX = (double)ft_save_info_player();
	// y-coordinate of the player as double
	ray.posY = (double)ft_save_info_player();
	// x-coordinate of the ray direction  
	ray.dirX = -1;
	// y-coordinate of the ray direction 
	ray.dirY = 0;
	ray.planeX = 0;    // 2D camera plane x-coordinate
	ray.planeY = 0.66; // 2D camera plane y-coordinate
	// Calculate ray position and direction
	ft_calculate_ray_position_direction(&ray);
}