/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:41:24 by mel-mora          #+#    #+#             */
/*   Updated: 2025/02/26 22:11:33 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static int	len_num(double num)
{
	int	len;

	len = 0;
	while (num > 1)
	{
		num /= 10;
		len++;
	}
	return (len);
}

double	atodbl(char *str)
{
	double	res;
	double	dec;
	int		sign;
	int		i;

	res = 0;
	dec = 0;
	sign = 1;
	i = 0;
	if (str[i++] == '-')
		sign = -1;
	while (str[i] && str[i] != '.')
		res = res * 10 + str[i++] - '0';
	if (str[i++] == '.')
	{
		while (str[i])
			dec = dec * 10 + str[i++] - '0';
	}
	return (sign * (res + dec / pow(10, len_num(dec))));
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->size_line) + (x * (data->bits_per_pixel / 8));
	*(unsigned int *)(data->pixels + offset) = color;
}
