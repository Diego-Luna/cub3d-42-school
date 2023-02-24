/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:25:31 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/24 14:05:43 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/ft_cub3d.h"
#include <string.h>
#define WIDTH 512
#define HEIGHT 512

static mlx_image_t	*img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}

int	main(int ac, char **av)
{
	// mlx_t	*mlx;
	t_state state;

	if (ac != 2)
		return (0);
	if (!ft_checkfile(av[1]))
	{
		printf("Error check file!\n");
		return (0);
	}
	ft_start_state(&state);
	ft_save_map(&state, av[1]);

	state.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!state.mlx)
		return (0);
	printf("OK!\n");
	img = mlx_new_image(state.mlx, 128, 128);
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	mlx_image_to_window(state.mlx, img, 0, 0);
	mlx_loop_hook(state.mlx, &hook, state.mlx);
	mlx_loop(state.mlx);
	mlx_terminate(state.mlx);
	return (0);
}
