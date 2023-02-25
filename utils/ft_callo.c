/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_callo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:28:08 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/24 18:55:21 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	*ft_calloc(size_t size, size_t type)
{
	size_t		i;
	char	*str;

	i = 0;
	str = malloc(size * type);
	if (str == NULL)
		return (0);
	while (i < size * type)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_newstr(char *str)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = 0;
	new = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	size = ft_strlen(str);
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

char	*ft_free(char *src)
{
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
	t_map	*map;

	map = &state->map;
	ft_free_table(map->map);
	ft_free(map->no);
	ft_free(map->so);
	ft_free(map->we);
	ft_free(map->ea);
}
