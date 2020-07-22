/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_chainsaw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:09:22 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 14:46:32 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void			chainsaw_firing(t_data *data)
{
	if (!data->p.shot_fired)
	{
		data->p.shot_fired = 1;
		data->p.has_fired = 0;
	}
	data->weapon_texture = data->sprites[18];
}

short				use_chainsaw(t_data *data, short is_firing)
{
	static double	framedata;

	if (is_firing)
	{
		if (framedata <= CHAINSAW / 2)
			chainsaw_firing(data);
		else
		{
			data->weapon_texture = data->sprites[19];
			if (framedata >= CHAINSAW)
			{
				data->p.shot_fired = 0;
				framedata = 0;
			}
		}
		framedata += data->ftime;
	}
	else
	{
		data->weapon_texture = data->sprites[16];
		framedata = 0;
	}
	return (framedata == 0 ? 1 : 0);
}
