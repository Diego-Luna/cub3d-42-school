/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:25:31 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/23 13:47:18 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/ft_cub3d.h"
#include <string.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (!ft_checkfile(av[1]))
	{
		printf("Error check file!\n");
		return (0);
	}
	printf("OK!\n");
	return (0);
}
