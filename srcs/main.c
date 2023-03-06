/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   main.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/23 08:25:31 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/06 15:22:09 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_randomize(t_state *state)
{
	int32_t		i;
	int32_t		y;
	uint32_t	color;

	i = 0;
	y = 0;
	while (i < 128)
	{
		while (y < 128)
		{
			color = ft_pixel(rand() % 0xFF, rand() % 0xFF, rand() % 0xFF, rand()
					% 0xFF);
			mlx_put_pixel(state->img, i, y, color);
			y++;
		}
		i++;
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
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_state	*state;

	state = (t_state *)param;
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
	state.last_click_ticks = 0;
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
	if (!state.img)
	{
		mlx_close_window(state.mlx);
		return (EXIT_FAILURE);
	}
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
	mlx_terminate(state.mlx);
	ft_free_all(&state);
	return (EXIT_SUCCESS);
}

void	ft_error_print(char *msg)
{
	write(2, msg, ft_strlen(msg));
}
