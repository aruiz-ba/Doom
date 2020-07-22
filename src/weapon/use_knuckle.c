/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_knuckle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:09:49 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 14:44:37 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void			knuckle_firing(t_data *data, double framedata)
{
	if (framedata <= 1 * KNUCKLE / 5.0)
		data->weapon_texture = data->sprites[2];
	else if (framedata <= 2 * KNUCKLE / 5.0)
	{
		if (!data->p.shot_fired)
		{
			data->p.shot_fired = 1;
			data->p.has_fired = 0;
		}
		data->weapon_texture = data->sprites[3];
	}
	else if (framedata <= 3 * KNUCKLE / 5.0)
		data->weapon_texture = data->sprites[2];
	else
		data->weapon_texture = data->sprites[1];
}

short				use_knuckle(t_data *data, short is_firing)
{
	static double	framedata;

	if (is_firing && framedata == 0)
		framedata += data->ftime;
	if (framedata != 0)
	{
		if (framedata > KNUCKLE)
		{
			data->p.shot_fired = 0;
			framedata = 0;
		}
		else
		{
			knuckle_firing(data, framedata);
			framedata += data->ftime;
		}
	}
	else
		data->weapon_texture = data->sprites[0];
	return (framedata == 0 ? 1 : 0);
}
