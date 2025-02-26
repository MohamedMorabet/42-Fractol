/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:27:32 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/26 22:16:24 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		exit(1);
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
			WIDTH, HEIGHT, "Fract'ol");
	if (!fractol->mlx_window)
		mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
	fractol->img.img = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
		free(fractol->mlx_connection);
		exit(1);
	}
	fractol->img.pixels = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel,
			&fractol->img.size_line, &fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			hundle_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img, 0, 0);
}

void	mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (ft_strcmp(fractol->name, "mandelbrot") == 0)
	{
		c->a = z->a;
		c->i = z->i;
		z->a = 0.0;
		z->i = 0.0;
	}
	else if (ft_strcmp(fractol->name, "julia") == 0)
	{
		c->a = fractol->julia_x;
		c->i = fractol->julia_y;
	}
}

void	process_fractal(t_complex *z, t_complex c, t_fractol *fractol,
			int *color)
{
	int	i;

	i = 0;
	while (i < fractol->iterations)
	{
		*z = sum_complex(square_complex(*z), c);
		if ((z->a * z->a) + (z->i * z->i) > fractol->escape_value)
		{
			*color = map(i, BLACK, WHITE, fractol->iterations);
			return ;
		}
		i++;
	}
	*color = PSYCHEDELIC_PURPLE;
}

void	hundle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.a = (map(x, -2, 2, WIDTH) / fractol->zoom) + fractol->shift_x;
	z.i = (map(y, 2, -2, HEIGHT) / fractol->zoom) + fractol->shift_y;
	mandelbrot_or_julia(&z, &c, fractol);
	if (ft_strcmp(fractol->name, "burning_ship") == 0)
	{
		i = burning_ship(z, z, fractol->iterations, fractol->escape_value);
		color = map(i, BLACK, WHITE, fractol->iterations);
		my_mlx_pixel_put(&fractol->img, x, y, color);
		return ;
	}
	process_fractal(&z, c, fractol, &color);
	my_mlx_pixel_put(&fractol->img, x, y, color);
}
