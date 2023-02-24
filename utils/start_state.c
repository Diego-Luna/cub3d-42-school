/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:22:40 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/24 14:04:35 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	ft_start_state(t_state *state)
{
	state->map.map = NULL;
	state->map.w_map = 0;
	state->map.h_map = 0;
	state->map.no = NULL;
	state->map.so = NULL;
	state->map.we = NULL;
	state->map.ea = NULL;
	state->map.floor = NULL;
	state->map.ceilling = NULL;

	state->player.position_x = -1;
	state->player.position_y = -1;
	state->player.direccion = NO_D;
	state->player.angle = -1;
}

void	ft_save_data_state(t_state *state, char *file)
{
	ft_save_map(state, file);
}