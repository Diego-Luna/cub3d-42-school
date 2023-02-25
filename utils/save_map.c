/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:58:13 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/25 00:19:14 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	ft_check_character(char c)
{
	if (c == '1' || c == '0')
	{
		return (true);
	}
	return (false);
}

void	ft_save_map(t_state *state, char *file)
{
	int		i;
	int		wi;
	int		fd;
	char	*line;

	i = 0;
	wi = 0;
	fd = open(file, O_RDONLY);
	line = NULL;
	while (line != NULL || (i == 0))
	{
		line = ft_gnl(fd);
		if (line && ((ft_check_character(line[0]) == true || line[0] == ' ')
				&& ft_check_character(line[ft_strlen(line) - 2]) == true))
		{
			if (wi < ft_strlen(line))
				wi = ft_strlen(line);
			i++;
		}
		if (!line)
			break ;
	}
	state->map.h_map = i;
	state->map.w_map = wi;
	printf("\n diego high={%i} width={%i} \n", i, wi);
}
