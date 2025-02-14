/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:42:42 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/14 12:45:36 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations = 42;
}

//fractol_init.c
void fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		exit(1); // do it later
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, "Fract'ol");
	// if (!fractol->mlx_window)
	// 	mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
	fractol->img.img = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		// mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
		free(fractol->mlx_connection);
		exit(1); // do it later
	}
	fractol->img.pixels = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel, &fractol->img.size_line, &fractol->img.endian);

	// events_init(fractol); // do it later
	data_init(fractol); // do it later
}

void	hundle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int 		i;
	int 		color;

	i = 0;
	z.a = 0.0;
	z.i = 0.0;
	c.a = map(x, -2, 2, 0, WIDTH);
	c.i = map(y, 2, -2, 0, HEIGHT);
	while (i < fractol->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.a * z.a) + (z.i * z.i) > fractol->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractol->iterations);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractol->img, x, y, PSYCHEDELIC_PURPLE);
}

void	fractol_render(t_fractol *fractol)
{
	int x;
	int y;

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
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->img.img, 0, 0);
}

int main(int ac, char **av)
{
	t_fractol fractol;

    if ((ac == 2 && ft_strcmp(av[1], "mandelbort") == 0)
     || (ac == 4 && ft_strcmp(av[1], "julia") == 0))
    {
		fractol.name = av[1];
		fractol_init(&fractol);
		printf("Fract'ol is running...\n");
		fractol_render(&fractol);
		printf("Fract'ol has finished rendering.\n");
		mlx_loop(fractol.mlx_connection);
	}
	else
        its_error(ac, av);
    return (0);
} 