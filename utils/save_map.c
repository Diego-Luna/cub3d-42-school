/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:58:13 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/24 14:19:56 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

bool ft_ckeck_caracteer(char c){
	if (c == '1' || c == '0') {
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
		if (line && ((ft_ckeck_caracteer(line[0]) == true || line[0] == ' ') && ft_ckeck_caracteer(line[ft_strlen(line) - 2]) == true)){
			if (wi < ft_strlen(line)){
				wi = ft_strlen(line);
			}
			i++;
		}
		if (!line){
			break;
		}
	}
	state->map.h_map = i;
	state->map.w_map = wi;
	printf("\n diego high={%i} width={%i} \n", i, wi);
}