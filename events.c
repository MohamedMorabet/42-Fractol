/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:26:30 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/14 22:00:30 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_fractol *fractol)
{
    if (key == 53)
        close_handler(fractol);
    else if (key == 123) //left arrow
        fractol->shift_x += 0.2;
    else if (key == 124) //right arrow
        fractol->shift_x -= 0.2;
    else if (key == 126) //up arrow
        fractol->shift_y -= 0.2;
    else if (key == 125) //down arrow
        fractol->shift_y += 0.2;
    else if (key == 69) //plus
        fractol->iterations += 1;
    else if (key == 78) //minus
        fractol->iterations -= 1;
    // refresh the image
    fractol_render(fractol);
    return (0);
}


int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
    if (button == 4)
    {
        fractol->shift_x += 0.2;
        fractol->shift_y += 0.2;
    }
    else if (button == 5)
    {
        fractol->shift_x -= 0.2;
        fractol->shift_y -= 0.2;
    }
    // refresh the image
    fractol_render(fractol);
    return (0);
}

int	close_handler(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
    mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
    free(fractol->mlx_connection);
    printf("\033[1;31m.\n..\n...\n👀 Whoa! \nEscaping? Fine... shutting down Fract'ol.\n\nSee you in another dimension! 🌌🔮\033[0m\n");
    exit(0);
}