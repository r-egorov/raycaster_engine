/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:21:24 by cisis             #+#    #+#             */
/*   Updated: 2021/01/29 14:38:01 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_custom_error_message(void)
{
	if (g_errno == 1)
		ft_putendl_fd("Invalid parameter in the map file", 2);
	else
		ft_putendl_fd("Custom error", 2);
}

int			process_error(void)
{
	ft_putendl_fd("Error", 2);
	if (errno)
		perror("cub3D");	
	else
	{
		ft_putstr_fd("cub3D: ", 2);
		print_custom_error_message();
	}
	return (-1);
}
