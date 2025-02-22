/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:31:04 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/16 09:29:48 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, KEYPRESS, 0, key_handler, fractol);
	mlx_hook(fractol->mlx_window, BUTTONPRESS, 0, mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, DESTROYNOTIFY, 0, close_handler, fractol);
	mlx_hook(fractol->mlx_window, MONTIONNOTIFY, 0, mouse_track, fractol);
}
