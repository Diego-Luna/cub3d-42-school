/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:39:49 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/23 12:54:34 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

bool	ft_checkfile(char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	*str[8];

	i = 0;
	str[0] = "NO";
	str[1] = "SO";
	str[2] = "WE";
	str[3] = "EA";
	str[4] = "\n";
	str[5] = "F";
	str[6] = "C";
	str[7] = "\n";
	fd = open(file, O_RDONLY);
	line = ft_gnl(fd);
	if (!ft_strchr(file, EXTENSION) || !line)
		return (close(fd), false);
	while (line)
	{
		free(line);
		line = ft_gnl(fd);
		i += 1;
	}
	return (close(fd), true);
}

bool	ft_strchr(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return (true);
			j += 1;
		}
		i += 1;
	}
	return (false);
}
