/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:41:24 by mel-mora          #+#    #+#             */
/*   Updated: 2025/03/02 12:25:32 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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

void	ft_exit(void)
{
	ft_printf("\033[1;31m🚨 ERROR: Invalid input! "
		"Please provide a valid number.\033[0m\n");
	exit(1);
}

double	parse_number(char *str, int *i)
{
	double	part;

	part = 0;
	while (str[*i] && str[*i] != '.')
	{
		if (str[*i] < '0' || str[*i] > '9')
			ft_exit();
		part = part * 10 + str[(*i)++] - '0';
	}
	return (part);
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
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	res = parse_number(str, &i);
	if (str[i++] == '.')
		dec = parse_number(str, &i);
	return (sign * (res + dec / pow(10, len_num(dec))));
}
