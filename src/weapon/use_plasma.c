/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_plasma.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:35:38 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 14:45:37 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void			plasma_firing(t_data *data, double framedata)
{
	if (framedata <= 0.75 * PLASMA / 2.0)
		data->weapon_texture = data->sprites[30];
	else
	{
		if (!data->p.shot_fired)
		{
			data->p.shot_fired = 1;
			data->p.has_fired = 0;
		}
		data->weapon_texture = data->sprites[31];
	}
}

short				use_plasma(t_data *data, short is_firing)
{
	static double	framedata;

	if (is_firing && framedata == 0 && data->p.cells != 0)
	{
		data->p.cells--;
		framedata += data->ftime;
	}
	if (framedata != 0)
	{
		if (framedata >= PLASMA)
		{
			data->p.shot_fired = 0;
			framedata = 0;
		}
		else
		{
			plasma_firing(data, framedata);
			framedata += data->ftime;
		}
	}
	else
		data->weapon_texture = data->sprites[29];
	return (framedata == 0 ? 1 : 0);
}
