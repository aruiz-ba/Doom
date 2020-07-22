/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_shotgun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:24:27 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 14:33:42 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void			shotgun_sprite_selector(t_data *data, double framedata)
{
	if (framedata <= SHOTGUN / 8.0)
		data->weapon_texture = data->sprites[4];
	else if (framedata <= 2 * SHOTGUN / 8.0)
	{
		if (!data->p.shot_fired)
		{
			data->p.shot_fired = 1;
			data->p.has_fired = 0;
		}
		data->weapon_texture = data->sprites[5];
	}
	else if (framedata <= 3 * SHOTGUN / 8.0)
		data->weapon_texture = data->sprites[7];
	else if (framedata <= 4 * SHOTGUN / 8.0)
		data->weapon_texture = data->sprites[8];
	else if (framedata <= 5 * SHOTGUN / 8.0)
		data->weapon_texture = data->sprites[9];
	else if (framedata <= 6 * SHOTGUN / 8.0)
		data->weapon_texture = data->sprites[8];
	else if (framedata <= 7 * SHOTGUN / 8.0)
		data->weapon_texture = data->sprites[7];
	else
		data->weapon_texture = data->sprites[6];
}

short				use_shotgun(t_data *data, short is_firing)
{
	static double	framedata;

	if (is_firing && framedata == 0 && data->p.shells != 0)
	{
		data->p.shells--;
		framedata += data->ftime;
	}
	if (framedata != 0)
	{
		if (framedata > SHOTGUN)
		{
			data->p.shot_fired = 0;
			framedata = 0;
		}
		else
		{
			shotgun_sprite_selector(data, framedata);
			framedata += data->ftime;
		}
	}
	else
		data->weapon_texture = data->sprites[6];
	return (framedata == 0 ? 1 : 0);
}
