/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:07:43 by cisis             #+#    #+#             */
/*   Updated: 2021/02/16 11:38:20 by cisis            ###   ########.fr       */
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

void		launch_mlx(t_all all)
{
	all.window.win = mlx_new_window(all.window.mlx, all.parsed.res_width,
			all.parsed.res_height, "cub3D_cisis");
	get_textures(&all);
	mlx_loop_hook(all.window.mlx, infinite_hook, &all);
	mlx_hook(all.window.win, 2, 1L<<0, key_pressed_hook, &all);
	mlx_hook(all.window.win, 3, 1L<<1, key_released_hook, &all);
	mlx_loop(all.window.mlx);
}

/*void		init_player_pos(t_all *all)
{
	all->plr_pos.x = all->parsed.player_pos.x * SCALE + SCALE/2 - 2;
	all->plr_pos.y = all->parsed.player_pos.y * SCALE + SCALE/2 - 2;
}*/

int			main(int argc, char **argv)
{
	t_all		all;
	
	if (argc != 2)
		return (-1);

	init_struct(&all);
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
	printf("FT = %s\n", all.parsed.floor_texture_path);
	printf("CT = %s\n", all.parsed.ceiling_texture_path);
	print_strs(all.parsed.map);
	printf("map_height = %zu\n", all.parsed.map_height);
	printf("player_dir = %c\n", all.parsed.player_dir);
	printf("player_pos = [%d, %d]\n", (int)all.parsed.player_pos.x,
			(int)all.parsed.player_pos.y);
	init_player_position(&all);
/*
	all.plr_pos.x = all.parsed.player_pos.x + 0.5;
	all.plr_pos.y = all.parsed.player_pos.y + 0.5;

	// Initialisating values (FIXME need to depend on parsed player)
	all.plr_pos.dir.x = 1;
	all.plr_pos.dir.y = 0;
	all.plr_pos.plane.x = 0;
	all.plr_pos.plane.y = -0.66;
*/
	printf("x%f\ny%f\n", all.plr_pos.x, all.plr_pos.y);
	printf("w%d, a%d, s%d, d%d\n", all.keys.w, all.keys.a, all.keys.s, all.keys.d);
	launch_mlx(all);
	return (0);
}
