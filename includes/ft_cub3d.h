/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:28:14 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/27 12:44:51 by dluna-lo         ###   ########.fr       */
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
# include "mlx/include/MLX42/MLX42.h"

# define EXTENSION ".cub"

# define NO_D 0
# define D_NO 1
# define D_SO 2
# define D_WE 3
# define D_EA 4

typedef struct s_map
{
	char **map;
	int 	w_map;
	int 	h_map;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *floor;
	char *ceilling;
}					t_map;

typedef struct s_player
{
	int 	position_x;
	int 	position_y;
	int	 	direccion;
	int	 	angle;
}					t_player;

typedef struct s_state
{
	mlx_t	*mlx;
	t_map map;
	t_player player;
}					t_state;


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


// start_state
void	ft_start_state(t_state *state);
void	ft_save_map(t_state *state, char *file);

// valid map
bool ft_valid_map(t_state *state);

// Error
void	ft_error(t_state *state, char *msg);
void	ft_only_error(char *msg);

// utils
void	*ft_calloc(size_t size, size_t type);
char *ft_free(char *src);
char *ft_newstr(char *str);
void ft_free_all(t_state *state);

#endif
