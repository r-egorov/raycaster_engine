/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:07:43 by cisis             #+#    #+#             */
/*   Updated: 2021/02/02 14:19:44 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char **argv)
{
	t_parsed	parsed;
	void		*mlx;

	mlx = mlx_init();
	mlx_get_screen_size(mlx, &g_screen_width, &g_screen_height);
	g_screen_width = 1280;
	g_screen_height = 720;
	errno = 0;

	if (argc == 2)
	{
		if (parse_file(argv[1], &parsed) == -1)
			return (-1);
	}

	printf("height = %d\n", parsed.res_height);
	printf("width = %d\n", parsed.res_width);
	printf("NO = %s\n", parsed.north_texture_path);
	printf("SO = %s\n", parsed.south_texture_path);
	printf("WE = %s\n", parsed.west_texture_path);
	printf("EA = %s\n", parsed.east_texture_path);
	printf("S = %s\n", parsed.sprite_texture_path);
	printf("F = %d\n", parsed.floor_colour);
	printf("C = %d\n", parsed.ceiling_colour);
	return (0);
}
