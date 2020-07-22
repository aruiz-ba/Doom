/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:46:19 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/13 16:04:15 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "../inc/libft.h"

double		atof_annex(const char *str, unsigned int i, double res, double sign)
{
	unsigned int	j;
	unsigned int	k;

	j = 1;
	while (j < 10 && str[i + j] >= '0' && str[i + j] <= '9')
		j++;
	j--;
	k = -1;
	while (++k < j)
		res *= 10.0;
	res += (double)ft_atoi(str + i + 1) * sign;
	while (k-- > 0)
		res /= 10.0;
	return (res);
}

double		ft_atof(const char *str)
{
	unsigned int	i;
	double			res;
	double			sign;

	i = 0;
	res = 0.0;
	sign = 1.0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' && str[i + 1] >= '0'
			&& str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign = -1.0;
		res += (double)ft_atoi(str + i);
	}
	else
		return (0);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		res = atof_annex(str, i, res, sign);
	return (res);
}
