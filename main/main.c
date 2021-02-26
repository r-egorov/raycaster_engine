/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:07:43 by cisis             #+#    #+#             */
/*   Updated: 2021/02/26 11:19:40 by cisis            ###   ########.fr       */
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

void		print_sprites(t_fpoint *sprites, size_t size)
{
	size_t		i = 0;

	while (i < size)
	{
		printf("x: %f, y: %f\n", sprites[i].x, sprites[i].y);
		i++;
	}
}

void		launch_mlx(t_all all)
{
	all.window.win = mlx_new_window(all.window.mlx, all.parsed.res_width,
			all.parsed.res_height, "cub3D_cisis");
	get_textures(&all);
	all.window.frame.img = mlx_new_image(all.window.mlx,
										all.parsed.res_width,
										all.parsed.res_height);
	all.window.frame.addr = mlx_get_data_addr(all.window.frame.img,
										&(all.window.frame.bpp),
										&(all.window.frame.line_len),
										&(all.window.frame.endian));
	mlx_loop_hook(all.window.mlx, infinite_hook, &all);
	mlx_hook(all.window.win, 2, 1L<<0, key_pressed_hook, &all);
	mlx_hook(all.window.win, 3, 1L<<1, key_released_hook, &all);
	mlx_hook(all.window.win, 17, 1L<<17, close_window, &all);
	mlx_loop(all.window.mlx);
}

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
	printf("n_sprites = %d\n", all.parsed.n_sprites);
	print_sprites(all.parsed.sprites, all.parsed.n_sprites);
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
	printf("x%f\ny%f\n", all.plr_pos.x, all.plr_pos.y);
	printf("w%d, a%d, s%d, d%d\n", all.keys.w, all.keys.a, all.keys.s, all.keys.d);

	//cast_sprites(&all);
	
	launch_mlx(all);
	return (0);
}
