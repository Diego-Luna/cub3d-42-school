/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   validate.c                                     ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/25 01:29:05 by atopalli            ██║███████╗          */
/*   Updated: 2023/02/28 13:13:27 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_everything(t_state *state, char **av)
{
	if (state->map.ceilling_color == 0 || state->map.floor_color == 0)
	{
		ft_free(state->map.ea);
		ft_free(state->map.no);
		ft_free(state->map.so);
		ft_free(state->map.we);
		exit(0);
	}
	if (!(state->map.ea && state->map.no && state->map.so && state->map.we))
	{
		ft_free(state->map.ea);
		ft_free(state->map.no);
		ft_free(state->map.so);
		ft_free(state->map.we);
		exit(0);
	}
	ft_save_map(state, av[1]);
	ft_valid_map(state);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}
