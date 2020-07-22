/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_bfg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:00:29 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 14:37:15 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void			bfg_sprite_selector(t_data *data, double framedata)
{
	if (framedata <= 2 * BFG / 6.0)
		data->weapon_texture = data->sprites[24];
	else if (framedata <= 2.5 * BFG / 6.0)
	{
		if (!data->p.shot_fired)
		{
			data->p.shot_fired = 1;
			data->p.has_fired = 0;
		}
		data->weapon_texture = data->sprites[25];
	}
	else if (framedata <= 3 * BFG / 6.0)
		data->weapon_texture = data->sprites[27];
	else if (framedata <= 3.5 * BFG / 6.0)
		data->weapon_texture = data->sprites[28];
	else if (framedata <= 4 * BFG / 6.0)
		data->weapon_texture = data->sprites[27];
	else
		data->weapon_texture = data->sprites[26];
}

short				use_bfg(t_data *data, short is_firing)
{
	static double	framedata;

	if (is_firing && framedata == 0 && data->p.cells >= 10)
	{
		data->p.cells -= 10;
		framedata += data->ftime;
	}
	if (framedata != 0)
	{
		if (framedata > BFG)
		{
			data->p.shot_fired = 0;
			framedata = 0;
		}
		else
		{
			bfg_sprite_selector(data, framedata);
			framedata += data->ftime;
		}
	}
	else
		data->weapon_texture = data->sprites[26];
	return (framedata == 0 ? 1 : 0);
}
