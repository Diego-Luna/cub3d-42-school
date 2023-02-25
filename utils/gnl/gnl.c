/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:01:39 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/25 00:18:29 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s2)
	{
		while (s2[i])
		{
			str[i] = s2[i];
			i += 1;
		}
		free(s2);
	}
	j = -1;
	while (s1[++j])
	{
		str[i] = s1[j];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_gnl(int fd)
{
	char	*line;
	char	buff[2];
	int		ret;

	line = NULL;
	if (fd < 0)
		return (NULL);
	ret = read(fd, buff, 1);
	while (ret > 0)
	{
		buff[ret] = '\0';
		line = ft_strdup(buff, line);
		if (ft_strchr(line, "\n"))
			break ;
		ret = read(fd, buff, 1);
	}
	return (line);
}
