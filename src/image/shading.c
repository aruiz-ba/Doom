/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:17:04 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 16:41:29 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static Uint32	highlighted_color(Uint32 color)
{
	t_color	tmp;
	double	lbd;

	lbd = 0.5;
	tmp.number = color;
	tmp.channel[0] += (1 - lbd) * (255 - tmp.channel[0]);
	tmp.channel[1] += (1 - lbd) * (255 - tmp.channel[1]);
	tmp.channel[2] += (1 - lbd) * (255 - tmp.channel[2]);
	return (tmp.number);
}

Uint32			shaded_color(t_data *data, Uint32 color, double dist,
								t_object *obj)
{
	t_color	tmp;
	double	lbd;

	if (obj)
		if (data->time - obj->hl_time < 90 && obj->hl_time != 0
							&& obj->state != DYING)
			color = highlighted_color(color);
	if (!data->shaded)
		return (color);
	tmp.number = color;
	if (dist >= 5)
		dist = 5;
	lbd = 1 - (dist / 5) * 0.9;
	tmp.channel[0] *= lbd;
	tmp.channel[1] *= lbd;
	tmp.channel[2] *= lbd;
	if (color == 0x010101)
		tmp.number = 0x010101;
	return (tmp.number);
}
