/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:31:04 by mel-mora          #+#    #+#             */
/*   Updated: 2025/03/02 12:29:29 by mel-mora         ###   ########.fr       */
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
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->size_line) + (x * (data->bits_per_pixel / 8));
	*(unsigned int *)(data->pixels + offset) = color;
}
