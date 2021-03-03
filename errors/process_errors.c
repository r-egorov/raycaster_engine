/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:21:24 by cisis             #+#    #+#             */
/*   Updated: 2021/03/03 12:52:04 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_msgs(char *(*arr)[40])
{
	char **msgs;

	msgs = *arr;
	msgs[14] = "Invalid number of arguments in the NO, SO, WE or EA parameters";
	msgs[15] = "Invalid char in F or C parameters";
	msgs[16] = "Invalid F or C colour values (should be 0 - 255)";
	msgs[17] = "Invalid number of arguments in the F or C parameters";
	msgs[18] = "Invalid char in the map";
	msgs[19] = "Invalid zero position in the map";
	msgs[20] = "Invalid space position in the map";
	msgs[21] = "Invalid texture extension (has to be .xpm)";
	msgs[22] = "Invalid texture filename (too many dots)";
	msgs[23] = "Double player position";
	msgs[24] = "Double R parameter";
	msgs[25] = "Double NO parameter";
	msgs[26] = "Double SO parameter";
	msgs[27] = "Double WE parameter";
	msgs[28] = "Double EA parameter";
	msgs[29] = "Double S parameter";
	msgs[30] = "Double F parameter";
	msgs[31] = "Double C parameter";
	msgs[32] = "Invalid number of arguments";
}

static char	*get_error_message(int errcode)
{
	char *msgs[40];

	msgs[1] = "Not a .cub file";
	msgs[2] = "Malloc error";
	msgs[3] = "Map not last or some parameter missing";
	msgs[4] = "Nothing must appear in the file after the map";
	msgs[5] = "Redundant parameter before the map";
	msgs[6] = "Invalid map";
	msgs[7] = "No map";
	msgs[8] = "F and C should be either colours or textures";
	msgs[9] = "Unknown flag as the second argument, should be `--save`";
	msgs[10] = "Unknown parameter identifier";
	msgs[11] = "Invalid number of arguments in the R parameter";
	msgs[12] = "Invalid resolution value";
	msgs[13] = "Invalid texture file";
	fill_msgs(&msgs);
	return (msgs[errcode]);
}

static void	print_custom_error_message(void)
{
	ft_putendl_fd(get_error_message(g_errno), 2);
}

int			process_error(void)
{
	ft_putendl_fd("Error", 2);
	if (g_errno)
	{
		ft_putstr_fd("cub3D: ", 2);
		print_custom_error_message();
	}
	else
	{
		if (errno)
			perror("cub3D");
	}
	return (-1);
}
