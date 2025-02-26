/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:26:30 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/26 22:11:43 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_handler(int key, t_fractol *fractol)
{
	if (key == ESC_KEY)
		close_handler(fractol);
	else if (key == LEFTARROW)
		fractol->shift_x -= 0.2;
	else if (key == RIGHTARROW)
		fractol->shift_x += 0.2;
	else if (key == UPARROW)
		fractol->shift_y += 0.2;
	else if (key == DOWNARROW)
		fractol->shift_y -= 0.2;
	else if (key == PLUS_KEY)
		fractol->iterations += 1;
	else if (key == MINUS_KEY)
		fractol->iterations -= 1;
	fractol_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	double	cursor_re;
	double	cursor_im;

	cursor_re = map(x, -2, 2, WIDTH - 1) / fractol->zoom + fractol->shift_x;
	cursor_im = map(y, 2, -2, HEIGHT - 1) / fractol->zoom + fractol->shift_y;
	if (button == 4)
	{
		fractol->zoom *= 1.05;
		fractol->shift_x += (cursor_re - fractol->shift_x) * 0.05;
		fractol->shift_y += (cursor_im - fractol->shift_y) * 0.05;
	}
	else if (button == 5)
	{
		fractol->zoom /= 1.05;
		fractol->shift_x -= (cursor_re - fractol->shift_x) * 0.05;
		fractol->shift_y -= (cursor_im - fractol->shift_y) * 0.05;
	}
	fractol_render(fractol);
	return (0);
}

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	free(fractol->mlx_connection);
	printf("\033[1;31m.\n..\n...\n👀 Whoa! \nEscaping? Fine... "
		"shutting down Fract'ol.\n\nSee you in another dimension! 🌌🔮\033[0m\n");
	exit(0);
}
