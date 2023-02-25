/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:28:14 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/25 00:20:28 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
	char		**map;
	int			w_map;
	int			h_map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*floor;
	uint32_t	floor_color;
	char		*ceilling;
	uint32_t	ceilling_color;
}					t_map;

typedef struct s_player
{
	int	position_x;
	int	position_y;
	int	direccion;
	int	angle;
}					t_player;

typedef struct s_state
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		map;
	t_player	player;
}					t_state;

/*		utils		*/
/*		gnl			*/
//	gnl.c
char	*ft_gnl(int fd);
char	*ft_strdup(char *s1, char *s2);
int		ft_strlen(char *str);

//	pasring.c
bool	ft_complexfile(char *file, int i, t_state *state);
bool	ft_checkfile(char *file, t_state *state);
bool	ft_strchr(char *s1, char *s2);

// start_state
void	ft_start_state(t_state *state);
void	ft_save_map(t_state *state, char *file);

#endif
