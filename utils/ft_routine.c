/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:15:39 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/03 19:36:38 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_ray_loop(t_state *state)
{
	t_ray *ray;

	ray = &state->ray;

	ray->camerax = 2 * ray->pos.x / (double)screenWidth - 1;

	ray->raydir.x = ray->dir.x + state->player.planeX * ray->camerax;
	ray->raydir.y = ray->dir.y + state->player.planeY * ray->camerax;
	ray->map.x = (int)state->player.position_x;
	ray->map.y = (int)state->player.position_y;
	ray->d_delta.x = fabs(1 / ray->raydir.x);
	ray->d_delta.y = fabs(1 / ray->raydir.y);
	ray->hit = false;
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->d_side.x = ( state->player.position_x - ray->map.x) * ray->d_delta.x;
	}
	else
	{
		ray->step.x =  1;
		ray->d_side.x = (ray->map.x + 1.0 - state->player.position_x) * ray->d_delta.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->d_side.y = (state->player.position_y - ray->map.y) * ray->d_delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->d_side.y = (ray->map.y + 1.0 - state->player.position_y) * ray->d_delta.y;
	}
}

void	ft_check_side_hit(t_state *state)
{
	t_ray *ray;

	ray = &state->ray;
	if (ray->d_side.x < ray->d_side.y)
	{
		ray->d_side.x += ray->d_delta.x;
		ray->map.x += ray->step.x;
		ray->side = 0;
		if (ray->step.x >= 0)
			ray->side = 2;
	}
	else
	{
		ray->d_side.y += ray->d_delta.y;
		ray->map.y += ray->step.y;
		ray->side = 1;
		if (ray->step.y >= 0)
			ray->side = 3;
	}
}

// Perform DDA
void	ft_perform_DDA(t_state *state)
{
	t_ray *ray;
	bool	hit;

	ray = &state->ray;
	if (ray->d_side.x < ray->d_side.y)
	{
		ray->d_side.x += ray->d_delta.x;
		ray->map.x += ray->step.x;
		ray->side = 0;
	}
	else
	{
		ray->d_side.y += ray->d_delta.y;
		ray->map.y += ray->step.y;
		ray->side = 1;
	}
	hit = false;
	while (!hit)
	{
		ft_check_side_hit(state);
		if (state->map.map[ray->map.x][ray->map.y] == '1')
		{
			ray->hit = true;
		}
	}
}


void ft_ray_2(t_state *state)
{
	t_ray *ray;
	double	wall_distance;
	double	wall_x;
	int		line_height;

	ray = &state->ray;;
	if (!(ray->side % 2))
		wall_distance = (ray->d_side.x - ray->d_delta.x);
	else
		wall_distance = (ray->d_side.y - ray->d_delta.y);
	line_height = (int)(screenWidth / wall_distance);
	ray->draw.x = -line_height / 2 + screenWidth / 2;
	if (ray->draw.x < 0)
		ray->draw.x = 0;
	ray->draw.y = line_height / 2 + screenWidth / 2;
	if (ray->draw.y >= screenWidth)
		ray->draw.y = screenWidth - 1;
	if (ray->side % 2 == 0)
		wall_x = state->player.position_y + (wall_distance * ray->raydir.y);
	else
		wall_x = state->player.position_x + (wall_distance * ray->raydir.x);
}

void	ft_routine(void *param)
{
	t_state	*state;

	state = (t_state *)param;
  state->ray.pos.x = 0;
	state->ray.pos.y = screenWidth;
	while (state->ray.pos.x <= screenWidth + 1)
	{
		ft_ray_loop(state);
		ft_perform_DDA(state);
		ft_ray_2(state);
		state->ray.pos.x += PRECISION;
	}
}
