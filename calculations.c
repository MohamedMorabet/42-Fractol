/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:35:01 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/15 13:27:36 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double value, double new_min, double new_max, double old_max)
{
	return (new_min + (value - 0) * (new_max - new_min) / (old_max - 0));
}

// sun complex number
t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	res;

	res.a = a.a + b.a;
	res.i = a.i + b.i;
	return (res);
}

// square complex number
t_complex	square_complex(t_complex a)
{
	t_complex	res;

	res.a = a.a * a.a - a.i * a.i;
	res.i = 2 * a.a * a.i;
	return (res);
}
