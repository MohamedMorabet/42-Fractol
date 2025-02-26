/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:42:42 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/26 22:16:24 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		|| (ac == 4 && ft_strcmp(av[1], "julia") == 0) 
		|| (ac == 2 && ft_strcmp(av[1], "burning_ship") == 0))
	{
		fractol.name = av[1];
		if (ac == 4)
		{
			fractol.julia_x = atodbl(av[2]);
			fractol.julia_y = atodbl(av[3]);
		}
		fractol_init(&fractol);
		printf("\033[1;32m🚀 Fract'ol is starting... Let's create"
			" some fractal magic! ✨\033[0m\n");
		fractol_render(&fractol);
		printf("\033[1;34m🎨 Fract'ol is rendering... Sit back and"
			" enjoy the beauty! 🌌\033[0m\n");
		mlx_loop(fractol.mlx_connection);
	}
	else
		its_error(ac, av);
	return (0);
}
