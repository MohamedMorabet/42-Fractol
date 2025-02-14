/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:26:40 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/14 16:02:13 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
 
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
/*
 * COLORS
*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef unsigned char byte;
typedef struct s_data
{
    void    *mlx;
    void    *win;
}   t_data;

typedef struct s_img
{
    void    *img;
    char    *addr;
    char    *pixels;
    int     bits_per_pixel;    
    int     size_line;
    int     endian;
}   t_img;

typedef struct s_fractol
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_img   img;
    double  escape_value;
    int     iterations;
}  t_fractol;

//complex number
typedef struct s_complex
{
    double  a;
    double  i;
}   t_complex;

void    ft_fractol();
int     ft_strcmp(char *s1, char *s2);
void    ft_putstr_fd(char *s, int fd);
void    its_error(int ac, char **av);
double  map(double value, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex a, t_complex b);
t_complex   square_complex(t_complex a);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	hundle_pixel(int x, int y, t_fractol *fractol);
void	fractol_render(t_fractol *fractol);


#endif