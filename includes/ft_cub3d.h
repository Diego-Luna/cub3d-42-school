/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@42.quebec.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:28:14 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/24 03:03:50 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define EXTENSION ".cub"

/*		utils		*/
/*		gnl			*/
//	gnl.c
char	*ft_gnl(int fd);
char	*ft_strdup(char *s1, char *s2);
int		ft_strlen(char *str);

//	pasring.c
bool	ft_parsemap(int fd, char *line);
bool	ft_complexfile(char *file, int i);
bool	ft_checkfile(char *file);
bool	ft_strchr(char *s1, char *s2);

#endif
