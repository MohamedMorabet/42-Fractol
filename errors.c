/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:20:49 by mel-mora          #+#    #+#             */
/*   Updated: 2025/03/02 12:16:05 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_usage(void)
{
	ft_printf("\033[1;33m🚨 Invalid input! Here’s how to use Fract'ol:\033[0m\n");
	ft_printf("\033[1;34m-------------------------------------------\033[0m\n");
	ft_printf("\033[1;32mUsage:\033[0m ./fractol <fractal_name> "
		"[optional parameters]\n");
	ft_printf("\n\033[1;36mAvailable fractals:\033[0m\n");
	ft_printf(" - \033[1;35mmandelbrot\033[0m   → ./fractol mandelbrot\n");
	ft_printf(" - \033[1;35mjulia\033[0m		→ ./fractol julia <x> <y>\n");
	ft_printf("\n\033[1;34mExamples:\033[0m\n");
	ft_printf(" ./fractol mandelbrot\n");
	ft_printf(" ./fractol julia -0.8 0.156\n");
	ft_printf("\n\033[1;31mExiting now... Try again! 👀\033[0m\n");
	exit(1);
}

void	its_error(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("\033[1;31m🚨 ERROR: No arguments provided! I need some"
			" input to work my magic. ✨\033[0m\n");
		display_usage();
	}
	else if (ac > 4)
		ft_printf("\033[1;33m📢 Too many arguments! I'm not a "
			"supercomputer, keep it simple. 🧠\033[0m\n");
	else if (ac == 4 && ft_strcmp(av[1], "julia") != 0)
		ft_printf("\033[1;34m🤔 Did you mean: ./fractol julia [x]"
			" [y]? Try again! 🧐\033[0m\n");
	else if (ac != 4 && ft_strcmp(av[1], "julia") == 0)
		ft_printf("\033[1;34m🤔 Did you mean: ./fractol julia [x] "
			"[y]? Try again! 🧐\033[0m\n");
	else if (ac == 2 && ft_strcmp(av[1], "mandelbrot") != 0)
		ft_printf("\033[1;36m🔍 Did you mean: ./fractol mandelbrot?"
			" Check your spelling! 📝\033[0m\n");
	else if (ac != 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		ft_printf("\033[1;36m🔍 Did you mean: ./fractol mandelbrot?"
			" Check your spelling! 📝\033[0m\n");
	else
		ft_printf("\033[1;31m🛑 What kind of sorcery is this? Your "
			"input is all over the place! �\033[0m\n");
}
