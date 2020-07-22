/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objcast_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:10:50 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 18:00:44 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	set_objcast_values_2(t_data *data, t_objcast *val, t_sprite sprite)
{
	if (val->drawend.y >= SCREEN_HEIGHT)
		val->drawend.y = SCREEN_HEIGHT - 1;
	val->drawstart.y = -val->height / 2 + (SCREEN_HEIGHT + data->yaw) / 2
															+ val->movescreen;
	if (val->drawstart.y < 0)
		val->drawstart.y = 0;
	val->width = abs((int)(SCREEN_HEIGHT / val->pos.y)) * sprite.scale.x;
	val->drawstart.x = -val->width / 2 + val->screen_x;
	if (val->drawstart.x < 0)
		val->drawstart.x = 0;
	val->drawend.x = val->width / 2 + val->screen_x;
	if (val->drawend.x >= SCREEN_WIDTH)
		val->drawend.x = SCREEN_WIDTH - 1;
}

void		set_objcast_values(t_data *data, t_objcast *val, t_object *iterator,
																t_sprite sprite)
{
	val->relative_pos.x = iterator->pos.x - data->p.pos.x;
	val->relative_pos.y = iterator->pos.y - data->p.pos.y;
	val->invdet = 1.0 / (data->p.plane.x * data->p.dir.y
		- data->p.dir.x * data->p.plane.y);
	val->pos.x = val->invdet * (data->p.dir.y * val->relative_pos.x
		- data->p.dir.x * val->relative_pos.y);
	val->pos.y = val->invdet * (-data->p.plane.y * val->relative_pos.x
		+ data->p.plane.x * val->relative_pos.y);
	val->screen_x = ((SCREEN_WIDTH / 2) * (1 + val->pos.x / val->pos.y));
	val->height = abs((int)(SCREEN_HEIGHT / val->pos.y)) * sprite.scale.y;
	val->drawend.y = val->height / 2 + (SCREEN_HEIGHT + data->yaw) / 2;
	val->movescreen = get_movescreen_value(data, *val, iterator->sprite_pos);
	val->drawend.y += val->movescreen;
	set_objcast_values_2(data, val, sprite);
	iterator->pix_mid_x = (val->drawstart.x + val->drawend.x) / 2;
	iterator->pix_mid_y = (val->drawstart.y + val->drawend.y) / 2;
}
