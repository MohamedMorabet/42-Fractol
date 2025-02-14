/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:26:40 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/14 09:07:32 by mel-mora         ###   ########.fr       */
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
    int bits_per_pixel;    
    int     size_line;
    int     endian;
}   t_img;

#endif