/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:07:43 by cisis             #+#    #+#             */
/*   Updated: 2021/03/03 14:59:02 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	launch_mlx(t_all *all)
{
	get_textures(all);
	all->window.frame.img = mlx_new_image(all->window.mlx,
										all->parsed.res_width,
										all->parsed.res_height);
	if (all->window.frame.img == NULL)
		return ;
	all->window.frame.addr = mlx_get_data_addr(all->window.frame.img,
										&(all->window.frame.bpp),
										&(all->window.frame.line_len),
										&(all->window.frame.endian));
	if (all->save == 1)
		infinite_hook(all);
	else
	{
		all->window.win = mlx_new_window(all->window.mlx, all->parsed.res_width,
				all->parsed.res_height, "cub3D_cisis");
		if (all->window.win == NULL)
			return ;
		mlx_loop_hook(all->window.mlx, infinite_hook, all);
		mlx_hook(all->window.win, 2, 1L << 0, key_pressed_hook, all);
		mlx_hook(all->window.win, 3, 1L << 1, key_released_hook, all);
		mlx_hook(all->window.win, 17, 1L << 17, close_window, all);
		mlx_loop(all->window.mlx);
	}
}

static int	valid_floor_ceiling(t_parsed *parsed)
{
	if ((parsed->floor_colour && parsed->ceiling_colour) ||
		(parsed->floor_texture_path && parsed->ceiling_texture_path))
		return (1);
	g_errno = 8;
	process_error();
	return (0);
}

static int	valid_args(int argc, char **argv, t_all *all)
{
	if (argc == 2)
	{
		all->save = 0;
		return (1);
	}
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") != 0)
		{
			g_errno = 9;
			process_error();
			return (0);
		}
		all->save = 1;
		return (1);
	}
	g_errno = 32;
	process_error();
	return (0);
}

int			main(int argc, char **argv)
{
	t_all		all;

	init_struct(&all);
	if (!(valid_args(argc, argv, &all)))
		return (-1);
	all.window.mlx = mlx_init();
	errno = 0;
	if ((parse_file(argv[1], &(all.parsed)) == -1) ||
		!(valid_floor_ceiling(&(all.parsed))))
		return (-1);
	init_player_position(&all);
	launch_mlx(&all);
	return (0);
}
