/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   parsing.c                                      ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/02/26 22:53:21 by atopalli            ██║███████╗          */
/*   Updated: 2023/02/27 00:26:43 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

uint32_t	ft_atoul(char *str)
{
	int			i;
	uint32_t	nb;
	int			color;
	int			pos;

	i = 0;
	pos = 24;
	nb = 255;
	while (str[i] == ' ')
		i += 1;
	color = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		color = color * 10 + str[i] - '0';
		i += 1;
		if (str[i] == ',')
		{
			nb += color << pos;
			pos -= 8;
			i += 1;
			color = 0;
		}
	}
	if (i == 0 || str[i] != '\0')
		return (-1);
	return (nb);
}

char	*ft_parsepath(char *file)
{
	int		fd;
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (file[i] != '.')
		i += 1;
	path = ft_strdup(file + i, NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	return (close(fd), path);
}

//will be deleted when not needed no more
bool	ft_printmap(int fd, char *line)
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

bool	ft_complexfile(char *file, int i, t_state *state)
{
	char	*str[8];

	str[0] = "NO";
	str[1] = "SO";
	str[2] = "WE";
	str[3] = "EA";
	str[4] = "\n";
	str[5] = "F";
	str[6] = "C";
	str[7] = "\n";
	if (i == 0)
		state->map.no = ft_parsepath(file + 2);
	else if (i == 1)
		state->map.so = ft_parsepath(file + 2);
	else if (i == 2)
		state->map.we = ft_parsepath(file + 2);
	else if (i == 3)
		state->map.ea = ft_parsepath(file + 2);
	else if (i == 5)
		state->map.floor_color = ft_atoul(file + 1);
	else if (i == 6)
		state->map.ceilling_color = ft_atoul(file + 1);
	return (ft_strchr(file, str[i]));
}

bool	ft_checkfile(char *file, t_state *state)
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
			if (i == 7 || !ft_complexfile(line, i, state))
				break ;
			free(line);
			line = ft_gnl(fd);
			i += 1;
		}
		line = ft_gnl(fd);
	}
	if (i != 0 && i != 7)
		return (close(fd), false);
	ft_printmap(fd, line);
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
