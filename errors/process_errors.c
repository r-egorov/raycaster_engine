/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:21:24 by cisis             #+#    #+#             */
/*   Updated: 2021/02/02 12:00:28 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_error_message(int errcode)
{
	char *msgs[20];
	
	msgs[1] = "Invalid parameter in the map file";
	msgs[2] = "Malloc error";
	msgs[10] = "Unknown parameter identifier";
	msgs[11] = "Invalid number of parameters in resolution";
	msgs[12] = "Invalid char in the resolution";
	msgs[13] = "Invalid texture file";
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
