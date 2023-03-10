/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:58:13 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/06 18:53:35 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	ft_ckeck_caracteer(char c)
{
	if (c == '1' || c == '0')
	{
		return (true);
	}
	return (false);
}

bool	ft_ckeck_caracter_plus(char *line)
{
	if (((ft_ckeck_caracteer(line[0]) == true || line[0] == ' ')
			&& ft_ckeck_caracteer(line[ft_strlen(line) - 2]) == true))
	{
		return (true);
	}
	return (false);
}

int	ft_get_info_map(t_state *state, int i, int *start, int fd)
{
	int		count;
	int		wi;
	char	*line;

	wi = 0;
	count = 0;
	line = ft_gnl(fd);
	while (line != NULL)
	{
		if (line && ft_ckeck_caracter_plus(line) == true)
		{
			if (wi < ft_strlen(line))
				wi = ft_strlen(line);
			if (*start == -1)
				*start = count;
			i++;
		}
		line = ft_free(line);
		line = ft_gnl(fd);
		count++;
	}
	state->map.h_map = i;
	state->map.w_map = wi;
	return (count);
}

void	ft_crreate_map(t_state *state, char *file, int count, int start)
{
	int		i;
	int		fd;
	int		index_table;
	char	*line;

	(void)count;
	fd = open(file, O_RDONLY);
	i = 0;
	index_table = 0;
	line = ft_gnl(fd);
	while (line != NULL)
	{
		if (i >= start && index_table < state->map.h_map)
		{
			state->map.map[index_table] = ft_newstr(line);
			index_table++;
		}
		i++;
		line = ft_free(line);
		line = ft_gnl(fd);
	}
	ft_free(line);
	close(fd);
}

void	ft_save_map(t_state *state, char *file)
{
	int	i;
	int	fd;
	int	count;
	int	start;

	start = -1;
	fd = open(file, O_RDONLY);
	i = 0;
	count = ft_get_info_map(state, i, &start, fd);
	close(fd);
	i = state->map.h_map;
	state->map.map = ft_calloc(i + 1, sizeof(char *));
	if (!state->map.map)
		ft_error(state, "Error calloc");
	ft_crreate_map(state, file, i, start);
}
