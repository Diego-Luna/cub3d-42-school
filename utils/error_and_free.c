/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   error_and_free.c                               ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/24 18:20:51 by dluna-lo            ██║███████╗          */
/*   Updated: 2023/02/28 13:09:42 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(t_state *state, char *msg)
{
	ft_error_print(msg);
	ft_free_all(state);
	exit(0);
}

void	ft_only_error(char *msg)
{
	ft_error_print(msg);
	exit(0);
}

char	*ft_free(char *src)
{
	if (!src)
	{
		return (NULL);
	}
	if (src)
	{
		free(src);
	}
	return (NULL);
}

char	*ft_free_table(char **src)
{
	int	i;

	i = 0;
	if (!src)
	{
		return (NULL);
	}
	while (src[i])
	{
		ft_free(src[i]);
		i++;
	}
	free(src);
	return (NULL);
}

void	ft_free_all(t_state *state)
{
	ft_free_table(state->map.map);
	ft_free(state->map.no);
	ft_free(state->map.so);
	ft_free(state->map.we);
	ft_free(state->map.ea);
}
