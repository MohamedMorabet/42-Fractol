/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:26:40 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/16 09:30:55 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

// Constants
# define WIDTH 800
# define HEIGHT 800
# define KEYPRESS 2
# define BUTTONPRESS 4
# define DESTROYNOTIFY 17
# define MONTIONNOTIFY 6

// Colors
# define BLACK	0x000000 // RGB(0, 0, 0)
# define WHITE	0xFFFFFF // RGB(255, 255, 255)
# define RED		0xFF0000 // RGB(255, 0, 0)
# define GREEN	0x00FF00 // RGB(0, 255, 0)
# define BLUE	0x0000FF // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST		0xFF00FF  // A vibrant magenta
# define LIME_SHOCK			0xCCFF00  // A blinding lime
# define NEON_ORANGE			0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE	0x660066  // A deep purple
# define AQUA_DREAM			0x33CCCC  // A bright turquoise
# define HOT_PINK			0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE		0x0066FF  // A radiant blue
# define LAVA_RED			0xFF3300  // A bright, molten red

//image struct
typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*pixels;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

//fractol struct
typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;

//complex number
typedef struct s_complex
{
	double	a;
	double	i;
}	t_complex;

/*-------------------- Utility and String Functions --------------------*/
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
double		atodbl(char *str);

/*-------------------- Error Handling Functions --------------------*/
void		its_error(int ac, char **av);

/*-------------------- Fractal Calculation Functions --------------------*/
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	square_complex(t_complex a);
void		mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractol *fractol);

/*-------------------- Graphics and Rendering Functions --------------------*/
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
void		hundle_pixel(int x, int y, t_fractol *fractol);
void		fractol_render(t_fractol *fractol);

/*-------------------- Event Handling Functions --------------------*/
int			key_handler(int keysym, t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			mouse_track(int x, int y, t_fractol *fractol);
int			close_handler(t_fractol *fractol);

/*-------------------- Initialization Functions --------------------*/
void		data_init(t_fractol *fractol);
void		events_init(t_fractol *fractol);
void		fractol_init(t_fractol *fractol);

/*-------------------- Mathematical Functions --------------------*/
double		map(double value, double new_min, double new_max,
				double old_max);

#endif