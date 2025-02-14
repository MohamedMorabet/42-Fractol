/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:27:32 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/14 09:19:23 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    color_screen(t_data *data, int color);
int hundle_input(int key, t_data *data)
{
    if (key == 53)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    printf("The key pressed is: %d\n", key);
    return (0);
}
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void    color_screen(t_data *data, int color)
{
    t_img   img;
    img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
    int i = 200;
    int j = 0;
    while (i < 600)
    {
        j = 200;
        while (j < 600)
        {
            my_mlx_pixel_put(&img, i, j, color);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
}

int encode_rgb(byte r, byte g, byte b)
{
    return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_cube(t_img *img, int x, int y)
{
    int i;
    int j;
    int color;

    i = 200;
    while (i < 600)
    {
        j = 200;
        while (j < 600)
        {
            color = encode_rgb(255, 255, 255);
            my_mlx_pixel_put(img, i, j, color);
            if (i % 100 == 0 || i == j)
            {
                my_mlx_pixel_put(img, i, j, 0x000000FF);
            }
            if (j % 100 == 0)
            {
                my_mlx_pixel_put(img, i, j, 0x0000FF00);
            }
            j++;
        }
        i++;
    }
}



int main()
{
    t_data  data;
    t_img   img;

    data.mlx = mlx_init();
    if (!data.mlx)
    {
        printf("Error initializing MLX\n");
        return (1);
    }

    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fract-ol");
    if (!data.win)
    {
        printf("Error creating window\n");
        return (1);
    }
    img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);

    draw_cube(&img, 800, 800);

    mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);

    mlx_key_hook(data.win, hundle_input, &data);
    mlx_loop(data.mlx);
    return (0);
}
