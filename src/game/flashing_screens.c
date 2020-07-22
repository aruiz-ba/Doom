/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flashing_screens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:05:29 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 18:06:27 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	blue_hp_screen(t_data *data)
{
	double	lbd;
	t_color	tmp;
	int		i;

	if (data->time - data->p_armortime < 300 && data->p_armortime != 0)
	{
		lbd = 0.5;
		i = -1;
		while (++i < SCREEN_WIDTH * SCREEN_HEIGHT - 1)
		{
			tmp.number = data->pixels[i];
			if (tmp.channel[0] <= 138)
				tmp.channel[0] += (1 - lbd) * (138 - tmp.channel[2]);
			tmp.channel[1] /= 2;
			tmp.channel[2] /= 2;
			data->pixels[i] = tmp.number;
		}
	}
}

void	green_hp_screen(t_data *data)
{
	double	lbd;
	t_color	tmp;
	int		i;

	if (data->time - data->p_healtime < 300 && data->p_healtime != 0)
	{
		lbd = 0.5;
		i = -1;
		while (++i < SCREEN_WIDTH * SCREEN_HEIGHT - 1)
		{
			tmp.number = data->pixels[i];
			if (tmp.channel[1] <= 138)
				tmp.channel[1] += (1 - lbd) * (138 - tmp.channel[2]);
			tmp.channel[2] /= 2;
			tmp.channel[0] /= 2;
			data->pixels[i] = tmp.number;
		}
	}
}

void	red_hit_screen(t_data *data)
{
	double	lbd;
	t_color	tmp;
	int		i;

	if (data->death_screen)
		return ;
	if (data->time - data->p_dmgtime < 300 && data->p_dmgtime != 0)
	{
		lbd = 0.5;
		i = -1;
		while (++i < SCREEN_WIDTH * SCREEN_HEIGHT - 1)
		{
			tmp.number = data->pixels[i];
			if (tmp.channel[2] <= 138)
				tmp.channel[2] += (1 - lbd) * (138 - tmp.channel[2]);
			tmp.channel[1] /= 2;
			tmp.channel[0] /= 2;
			data->pixels[i] = tmp.number;
		}
	}
}
