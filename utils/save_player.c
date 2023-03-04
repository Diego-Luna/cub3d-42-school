/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:27:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/03 13:10:08 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_save_info_player(t_state *state, char c, int y, int x)
{
	if (c != 'N' || c != 'S' || c != 'E' || c != 'W')
		return;
	state->player.position_x = x;
	state->player.position_y = y;
	if (c == 'N')
	{
		state->player.direction = D_NO;
		state->player.planeX = 0;
		state->player.planeY = 0.66;
	}
	else if (c == 'S')
		state->player.direction = D_SO;
	else if (c == 'E')
		state->player.direction = D_EA;
	else if (c == 'W')
		state->player.direction = D_WE;
}

void	ft_player_start(t_state *state){
	ft_run_map_xy(state, ft_save_info_player);
}