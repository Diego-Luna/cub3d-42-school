/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:20:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/24 18:57:00 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cub3d.h"

void	ft_error_print(char *msg){
	write(2, msg, ft_strlen(msg));
}

void	ft_error(t_state *state, char *msg)
{
	ft_error_print(msg);
	ft_free_all(state);
	exit(0);
}
