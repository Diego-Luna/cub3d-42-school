/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:25:31 by atopalli          #+#    #+#             */
/*   Updated: 2023/03/03 13:15:48 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <string.h>
#define WIDTH 512
#define HEIGHT 512

void	ft_keys(void *param)
{
	t_state	*state;

	state = (t_state *)param;
	if (mlx_is_key_down(state->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(state->mlx);
		ft_error(state, NULL);
	}
	if (mlx_is_key_down(state->mlx, MLX_KEY_UP))
		state->img->instances[0].y -= 5;
	if (mlx_is_key_down(state->mlx, MLX_KEY_DOWN))
		state->img->instances[0].y += 5;
	if (mlx_is_key_down(state->mlx, MLX_KEY_LEFT))
		state->img->instances[0].x -= 5;
	if (mlx_is_key_down(state->mlx, MLX_KEY_RIGHT))
		state->img->instances[0].x += 5;
}

int	main(int ac, char **av)
{
	t_state	state;

	if (ac != 2)
		return (0);
	ft_start_state(&state);
	if (!ft_checkfile(av[1], &state))
	{
		ft_error(&state, "Error check file");
		return (0);
	}
	ft_check_everything(&state, av);
	state.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!state.mlx)
		return (0);

	state.img = mlx_new_image(state.mlx, 128, 128);
	mlx_put_string(state.mlx, "hello world", WIDTH / 2, HEIGHT / 2);
	mlx_image_to_window(state.mlx, state.img, 0, 0);

	mlx_loop_hook(state.mlx, &ft_routine, (void *)&state);
	mlx_loop_hook(state.mlx, &ft_keys, (void *)&state);
	mlx_loop(state.mlx);
	mlx_terminate(state.mlx);
	ft_free_all(&state);
	return (0);
}
