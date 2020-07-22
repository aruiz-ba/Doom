/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_handgun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:09:09 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 14:27:59 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void			handgun_spritte_selector(t_data *data, double framedata)
{
	if (framedata <= HANDGUN / 6.0)
	{
		if (!data->p.shot_fired)
		{
			data->p.shot_fired = 1;
			data->p.has_fired = 0;
		}
		data->weapon_texture = data->sprites[10];
	}
	else if (framedata <= 2 * HANDGUN / 6.0)
		data->weapon_texture = data->sprites[12];
	else if (framedata <= 3 * HANDGUN / 6.0)
		data->weapon_texture = data->sprites[15];
	else if (framedata <= 4 * HANDGUN / 6.0)
		data->weapon_texture = data->sprites[13];
	else if (framedata <= 5 * HANDGUN / 6.0)
		data->weapon_texture = data->sprites[14];
	else
		data->weapon_texture = data->sprites[11];
}

short				use_handgun(t_data *data, short is_firing)
{
	static double	framedata;

	if (is_firing && framedata == 0 && data->p.bullets != 0)
	{
		data->p.bullets--;
		framedata += data->ftime;
	}
	if (framedata != 0)
	{
		if (framedata >= HANDGUN)
		{
			data->p.shot_fired = 0;
			framedata = 0;
		}
		else
		{
			handgun_spritte_selector(data, framedata);
			framedata += data->ftime;
		}
	}
	else
		data->weapon_texture = data->sprites[11];
	return (framedata == 0 ? 1 : 0);
}
