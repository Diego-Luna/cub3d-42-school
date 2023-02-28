/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:28:08 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/28 11:54:20 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*ft_calloc(size_t size, size_t type)
{
	size_t	i;
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
