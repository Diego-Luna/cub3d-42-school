/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:25:31 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/25 01:39:47 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/cub3d.h"
#include <string.h>
#define WIDTH 512
#define HEIGHT 512

void	hook(void *param)
{
	t_state	*mlx;

	mlx = (t_state *)param;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx->mlx);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_UP))
		mlx->img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_DOWN))
		mlx->img->instances[0].y += 5;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
		mlx->img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
		mlx->img->instances[0].x += 5;
}

int	main(int ac, char **av)
{
	t_state		state;

	if (ac != 2)
		return (0);
	if (!ft_checkfile(av[1], &state))
	{
		printf("Error check file!\n");
		return (0);
	}
	ft_start_state(&state);
	ft_save_map(&state, av[1]);
	state.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!state.mlx)
		return (0);
	printf("OK!\n");
	state.img = mlx_new_image(state.mlx, 128, 128);
	memset(state.img->pixels, 255, state.img->width
		* state.img->height * sizeof(int));
	mlx_image_to_window(state.mlx, state.img, 0, 0);
	mlx_loop_hook(state.mlx, &hook, (void *)&state);
	mlx_loop(state.mlx);
	mlx_terminate(state.mlx);
	return (0);
}
