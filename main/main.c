/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:07:43 by cisis             #+#    #+#             */
/*   Updated: 2021/02/05 14:52:19 by cisis            ###   ########.fr       */
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
	t_all		all;
	
	if (argc != 2)
		return (-1);

	all.window.mlx = mlx_init();
	mlx_get_screen_size(all.window.mlx, &g_screen_width, &g_screen_height);
	errno = 0;


	if (parse_file(argv[1], &(all.parsed)) == -1)
		return (-1);
	printf("height = %d\n", all.parsed.res_height);
	printf("width = %d\n", all.parsed.res_width);
	printf("NO = %s\n", all.parsed.north_texture_path);
	printf("SO = %s\n", all.parsed.south_texture_path);
	printf("WE = %s\n", all.parsed.west_texture_path);
	printf("EA = %s\n", all.parsed.east_texture_path);
	printf("S = %s\n", all.parsed.sprite_texture_path);
	printf("F = %d\n", all.parsed.floor_colour);
	printf("C = %d\n", all.parsed.ceiling_colour);
	print_strs(all.parsed.map);
	printf("map_height = %zu\n", all.parsed.map_height);
	printf("player_dir = %c\n", all.parsed.player_dir);
	printf("player_pos = [%d, %d]\n", all.parsed.player_pos.x, all.parsed.player_pos.y);

	printf("===========\nHERE\n============\n");
	all.window.win = mlx_new_window(all.window.mlx, all.parsed.res_width,
			all.parsed.res_height, "cub3D_cisis");
	mlx_loop_hook(all.window.mlx, render_next_frame, &all);
	mlx_loop(all.window.mlx);
	return (0);
}
/*
int			main(int argc, char **argv)
{
	t_all		all;

	if (argc != 2)
		return (0);

	//if (parse_file(argv[1], all.parsed) == -1)
	//	return (-1);
	printf("%s\n", argv[1]);
	all.window->mlx = mlx_init();
	all.window->win = mlx_new_window(all.window->mlx, 640, 480,
			"cub3D_cisis");
	mlx_loop(all.window->mlx);
}*/
