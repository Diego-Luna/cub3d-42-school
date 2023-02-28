/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   start_state.c                                  ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/24 13:22:40 by dluna-lo            ██║███████╗          */
/*   Updated: 2023/02/27 22:18:26 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_start_state(t_state *state)
{
	state->map.map = NULL;
	state->map.w_map = 0;
	state->map.h_map = 0;
	state->map.no = ft_parsepath("./includes/imgs/north.png");
	state->map.so = ft_parsepath("./includes/imgs/south.png");
	state->map.we = ft_parsepath("./includes/imgs/west.png");
	state->map.ea = ft_parsepath("./includes/imgs/east.png");
	state->map.floor_color = ft_atoul("76,208,240");
	state->map.ceilling_color = ft_atoul("52,86,110");
	state->player.position_x = -1;
	state->player.position_y = -1;
	state->player.direction = NO_D;
	state->player.angle = -1;
}

void	ft_save_data_state(t_state *state, char *file)
{
	ft_save_map(state, file);
}
