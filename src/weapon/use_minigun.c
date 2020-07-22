/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_minigun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:14:06 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 14:30:30 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void			minigun_sprite_selector(t_data *data, double framedata)
{
	if (framedata <= MINIGUN / 4.0)
		data->weapon_texture = data->sprites[22];
	else if (framedata <= 2 * MINIGUN / 4.0)
		data->weapon_texture = data->sprites[20];
	else if (framedata <= 3 * MINIGUN / 4.0)
	{
		if (!data->p.shot_fired)
		{
			data->p.shot_fired = 1;
			data->p.has_fired = 0;
		}
		data->weapon_texture = data->sprites[23];
	}
	else
		data->weapon_texture = data->sprites[21];
}

short				use_minigun(t_data *data, short is_firing)
{
	static double	framedata;

	if (is_firing && framedata == 0 && data->p.bullets != 0)
	{
		data->p.bullets--;
		framedata += data->ftime;
	}
	if (framedata != 0)
	{
		if (framedata > 0.1)
		{
			data->p.shot_fired = 0;
			framedata = 0;
		}
		else
		{
			minigun_sprite_selector(data, framedata);
			framedata += data->ftime;
		}
	}
	else
		data->weapon_texture = data->sprites[23];
	return (framedata == 0 ? 1 : 0);
}
