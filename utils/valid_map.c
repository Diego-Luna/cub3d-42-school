/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:15:17 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/03 13:03:25 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_run_map_xy(t_state *state, void (*f)(t_state *, char, int, int))
{
	int x;
	int y;

	y = 0;
	while(state->map.map[y])
	{
		x = 0;
		while (state->map.map[y][x])
		{
			(*f)(state, state->map.map[y][x], y, x);
			x++;
		}
		y++;
	}
}

void ft_valid_map_caracter(t_state *state, char c, int y, int x)
{
	(void)y,
	(void)x;
	if (!(c == ' ' || c == '\0' || c == '\n' || c == 'N' || c == 'S' ||
				c == 'E' || c == 'W' || c == '1' || c == '0'))
	{
		ft_error(state, "Error no digit valid");
	}
}

void ft_is_map_close(t_state *state, char c, int y, int x)
{
	char **map;

	map = state->map.map;
	if (c != '0')
		return;
	if (x != 0 && y != 0 && (map[y][x - 1] == ' ' || map[y][x + 1] == ' ' || map[y - 1][x] == ' ' || map[y + 1][x] == ' ') )
		ft_error(state, "Error no Map valid");
	if (x == 0 || y == 0 ||
		(x == state->map.w_map - 1) ||
		y == state->map.h_map - 1)
		ft_error(state, "Error no Map valid");
}

void ft_is_user(t_state *state, char c, int y, int x)
{
	static int number = 0;

	(void)x;
	(void)y;
	if(c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		number++;
	}
	if (number > 1){
		ft_error(state, "Error user no valid");
	}
}

bool ft_valid_map(t_state *state)
{
	ft_run_map_xy(state, ft_valid_map_caracter);
	ft_run_map_xy(state, ft_is_map_close);
	ft_run_map_xy(state, ft_is_user);
	return true;
}
