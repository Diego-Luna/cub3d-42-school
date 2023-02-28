/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   ray_converted.c                                ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/28 13:46:10 by atopalli            ██║███████╗          */
/*   Updated: 2023/02/28 14:24:00 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define WIDTH 640

typedef struct ray_converted
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	deltaDistX;
	double	deltaDistY;
	int		hit;
}			ray_converted;

void	ft_calculate_ray_position_direction(ray_converted *ray, int x)
{
	// Calculate ray position and direction
	ray->cameraX = 2 * x / (double)WIDTH - 1;
	// x-coordinate in camera space
	ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
	ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
	// Which box of the map we're in
	ray->mapX = (int)ray->posX;
	ray->mapY = (int)ray->posY;
	// Length of ray from current position to next x or y-side
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0; // Was there a wall hit?
}

void	ft_func(void)
{
	ray_converted ray;

	// Initialize raycasting variables
	ray.posX = (double)ft_save_info_player(); // x-coordinate of the player
	ray.posX = (double)ft_save_info_player(); // x-coordinate of the player
	ray.posY = (double)ft_save_info_player(); // y-coordinate of the player
	ray.dirX = -1;
	// x-coordinate of the ray direction
	ray.dirY = 0;
	// y-coordinate of the ray direction
	ray.planeX = 0;    // 2D camera plane x-coordinate
	ray.planeY = 0.66; // 2D camera plane y-coordinate

	// Calculate ray position and direction
	ft_calculate_ray_position_direction(&ray, )
}