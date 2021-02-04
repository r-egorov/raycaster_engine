/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:07:43 by cisis             #+#    #+#             */
/*   Updated: 2021/02/03 17:40:46 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void print_strs(char **strs) // PRINTF
{
	int i = 0;
	if (strs)
	{
		while (strs[i])
		{
			printf("%s\n", strs[i++]);
		}
	}
}

int			main(int argc, char **argv)
{
	t_parsed	parsed;
	void		*mlx;

	mlx = mlx_init();
	mlx_get_screen_size(mlx, &g_screen_width, &g_screen_height);
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
	print_strs(parsed.map);
	printf("map_height = %zu\n", parsed.map_height);
	return (0);
}
