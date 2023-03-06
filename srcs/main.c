/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:25:31 by atopalli          #+#    #+#             */
/*   Updated: 2023/03/06 13:54:50 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_randomize(t_state *state)
{
	for (int32_t i = 0; i < 128; ++i)
	{
		for (int32_t y = 0; y < 128; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(state->img, i, y, color);
		}
	}
}

void	follow_mouse(t_state *state)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(state->mlx, &x, &y);
	if (x >= 0 && y >= 0 && x < HEIGHT && y < WIDTH)
	{
		state->img->instances[0].x = x;
		state->img->instances[0].y = y;
		state->no->instances[0].x = x + 50;
		state->no->instances[0].y = y + 50;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_state	*state;

	state = (t_state *)param;
	printf("key: %d, action: %d, modifier: %d\n", keydata.key, keydata.action,
			keydata.modifier);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(state->mlx);
		if (keydata.key == MLX_KEY_UP)
			state->img->instances[0].y -= 5;
		if (keydata.key == MLX_KEY_DOWN)
			state->img->instances[0].y += 5;
		if (keydata.key == MLX_KEY_LEFT)
			state->img->instances[0].x -= 5;
		if (keydata.key == MLX_KEY_RIGHT)
			state->img->instances[0].x += 5;
	}
}

void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods,
		void *param)
{
	t_state	*state;

	state = (t_state *)param;
	printf("button: %d, action: %d, mods: %d\n", button, action, mods);
}

void	ft_keys(void *param)
{
	t_state	*state;

	state = (t_state *)param;
	state->ticks++;
	ft_randomize(state);
	follow_mouse(state);
}

int	main(int ac, char **av)
{
	t_state	state;

	if (ac != 2)
		return (0);
	state.ticks = 0;
	state.lastClickTicks = 0;
	ft_start_state(&state);
	if (!ft_checkfile(av[1], &state))
	{
		ft_error(&state, "Error check file");
		return (0);
	}
	ft_check_everything(&state, av);
	state.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!state.mlx)
		return (EXIT_FAILURE);
	state.img = mlx_new_image(state.mlx, 128, 128);
	state.no = mlx_new_image(state.mlx, 128, 128);
	if (!state.img)
	{
		mlx_close_window(state.mlx);
		return (EXIT_FAILURE);
	}
	mlx_image_to_window(state.mlx, state.no, 0, 0);
	if (mlx_image_to_window(state.mlx, state.img, 55, 55) == -1)
	{
		mlx_close_window(state.mlx);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(state.mlx, key_hook, (void *)&state);
	mlx_mouse_hook(state.mlx, mouse_hook, (void *)&state);
	mlx_loop_hook(state.mlx, &ft_keys, (void *)&state);
	mlx_loop_hook(state.mlx, &ft_routine, (void *)&state);
	mlx_loop(state.mlx);
	// mlx_terminate(state.mlx);
	// ft_free_all(&state);
	return (EXIT_SUCCESS);
}

void	ft_error_print(char *msg)
{
	write(2, msg, ft_strlen(msg));
}
