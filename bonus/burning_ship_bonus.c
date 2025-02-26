/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:03:14 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/26 22:12:00 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	burning_ship(t_complex z, t_complex c, int max_iterations, 
			double escape_value)
{
	int	i;

	i = 0;
	while (i < max_iterations)
	{
		z = sum_complex(square_complex((t_complex){-fabs(z.a), fabs(z.i)}), c);
		if ((z.a * z.a) + (z.i * z.i) > escape_value)
			break ;
		i++;
	}
	return (i);
}
