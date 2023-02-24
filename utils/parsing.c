/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:39:49 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/24 11:34:52 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

bool	ft_parsemap(int fd, char *line)
{
	if (!line)
		line = ft_gnl(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = ft_gnl(fd);
	}
	return (close(fd), true);
}

bool	ft_complexfile(char *file, int i)
{
	// void	(*ptr_func[8])(char *);
	char	*str[8];

	// ptr_func[0] = ft_northimg;
	// ptr_func[1] = ft_southimg;
	// ptr_func[2] = ft_westimg;
	// ptr_func[3] = ft_eastimg;
	// ptr_func[5] = ft_floorimg;
	// ptr_func[6] = ft_ceillingimg;
	str[0] = "NO";
	str[1] = "SO";
	str[2] = "WE";
	str[3] = "EA";
	str[4] = "\n";
	str[5] = "F";
	str[6] = "C";
	str[7] = "\n";
	// if (i != 4 && i != 7 && ft_strchr(file, str[i]))
	// 	ptr_func[i](file + 2);
	return (ft_strchr(file, str[i]));
}

bool	ft_checkfile(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = ft_gnl(fd);
	if (!ft_strchr(file, EXTENSION) || !line)
		return (close(fd), false);
	if (line[0] == 'N' && line[1] == 'O')
	{
		while (1)
		{
			if (i == 7 || !ft_complexfile(line, i))
				break ;
			free(line);
			line = ft_gnl(fd);
			i += 1;
		}
		line = ft_gnl(fd);
	}
	if (i != 0 && i != 7)
		return (close(fd), false);
	return (ft_parsemap(fd, line));
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
