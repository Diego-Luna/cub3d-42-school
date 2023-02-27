/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_callo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:28:08 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/27 12:38:49 by dluna-lo         ###   ########.fr       */
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
		ft_only_error("Error in malloc");
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
	if (!new)
		ft_only_error("Error in malloc");
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
	if (!src){
		return NULL;
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
	if (!src){
		return NULL;
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
