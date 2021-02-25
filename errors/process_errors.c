/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:21:24 by cisis             #+#    #+#             */
/*   Updated: 2021/02/25 18:34:32 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_error_message(int errcode)
{
	char *msgs[40];

	msgs[1] = "Not a .cub file";
	msgs[2] = "Malloc error";
	msgs[3] = "Ivalid order of parameters, map must be the last";
	msgs[4] = "Nothing must appear in the file after the map";
	msgs[5] = "Redundant parameter before the map";
	msgs[10] = "Unknown parameter identifier";
	msgs[11] = "Invalid number of arguments in the R parameter";
	msgs[12] = "Invalid resolution value";
	msgs[13] = "Invalid texture file";
	msgs[14] = "Invalid number of arguments in the NO, SO, WE or EA parameters";
	msgs[15] = "Invalid char in F or C parameters";
	msgs[16] = "Invalid F or C colour values (should be 0 - 255)";
	msgs[17] = "Invalid number of arguments in the F or C parameters";
	msgs[18] = "Invalid char in the map";
	msgs[19] = "Invalid zero position in the map";
	msgs[20] = "Invalid space position in the map";
	msgs[21] = "Invalid texture extension (has to be .png)";
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
