/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:07:43 by cisis             #+#    #+#             */
/*   Updated: 2021/01/29 17:44:44 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char **argv)
{
	t_parsed	parsed;
/*	void		*mlx;

	mlx = mlx_init();
	mlx_get_screen_size(mlx, &g_screen_width, &g_screen_height);
*/
	if (argc == 2)
	{
		if (parse_file(argv[1], &parsed) == -1)
			return (-1);
	}

	printf("height = %d\n", parsed.res_height);
	printf("width = %d\n", parsed.res_width);
	return (0);
}
