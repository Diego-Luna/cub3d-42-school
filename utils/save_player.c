/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   save_player.c                                  ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/28 11:27:35 by dluna-lo            ██║███████╗          */
/*   Updated: 2023/02/28 13:10:07 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_save_info_player(t_state *state, char c, int y, int x)
{
	if (c != 'N' || c != 'S' || c != 'E' || c != 'W')
		return ;
	state->player.position_x = x;
	state->player.position_y = y;
	if (c == 'N')
		state->player.direction = D_NO;
	else if (c == 'S')
		state->player.direction = D_SO;
	else if (c == 'E')
		state->player.direction = D_EA;
	else if (c == 'W')
		state->player.direction = D_WE;
}

void	ft_player_start(t_state *state)
{
	ft_run_map_xy(state, ft_save_info_player);
}
