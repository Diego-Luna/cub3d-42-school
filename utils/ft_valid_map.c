/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:15:17 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/24 19:34:20 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	ft_run_map_xy(t_state *state, void (*f)(t_state *, char, int, int))
{
	int x;
	int y;
	int number_capacter;

	y = 0;
	number_capacter = 0;
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
	if (x == 0 || y == 0)
	{
		ft_error(state, "Error no digit valid");
	}
}

bool ft_valid_map(t_state *state)
{
	ft_run_map_xy(state, ft_valid_map_caracter);
	ft_run_map_xy(state, ft_is_map_close);
	return true;
}
