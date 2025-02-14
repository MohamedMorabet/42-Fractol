/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:41:24 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/14 11:29:17 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// ft_strcmp.c
int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

// putstr_fd.c
void    ft_putstr_fd(char *s, int fd)
{
    int i;
    
    i = 0;
    if (!s || fd < 0)
        return ;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

// math_utils.c
double  map(double value, double new_min, double new_max, double old_min, double old_max)
{
    return (new_min + (value - old_min) * (new_max - new_min) / (old_max - old_min));
}

// sun complex number
t_complex   sum_complex(t_complex a, t_complex b)
{
    t_complex res;

    res.a = a.a + b.a;
    res.i = a.i + b.i;
    return (res);
}

// square complex number
t_complex   square_complex(t_complex a)
{
    t_complex res;

    res.a = a.a * a.a - a.i * a.i;
    res.i = 2 * a.a * a.i;
    return (res);
}