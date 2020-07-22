/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:19:17 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:40:16 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			get_moving_sprite(t_data *data, t_object *obj)
{
	obj->lastupdate += data->ftime;
	if (obj->current_sprite < obj->first_sprite_walk
		|| obj->current_sprite > obj->first_sprite_walk
		+ obj->num_of_sprites_walk)
	{
		obj->lastupdate = 0;
		obj->current_sprite = obj->first_sprite_walk;
	}
	else if (obj->lastupdate >= 1.0 / obj->num_of_sprites_walk)
	{
		obj->lastframe++;
		obj->lastframe %= obj->num_of_sprites_walk;
		obj->lastupdate = 0;
		obj->current_sprite = obj->first_sprite_walk + obj->lastframe;
	}
}

void			move_obj(t_data *data, t_d_point dir, t_object *obj)
{
	if (data->cur_map.map[(int)(obj->pos.x + dir.x * obj->move_speed
		* data->ftime)][(int)(obj->pos.y)] == 0)
		obj->pos.x += dir.x * obj->move_speed * data->ftime;
	if (data->cur_map.map[(int)(obj->pos.x)][(int)(obj->pos.y + dir.y
		* obj->move_speed * data->ftime)] == 0)
		obj->pos.y += dir.y * obj->move_speed * data->ftime;
}

void			pathfind(t_data *data, t_object *obj)
{
	double		mag;
	t_d_point	dir;

	mag = sqrt((data->p.pos.x - obj->pos.x)
		* (data->p.pos.x - obj->pos.x)
		+ (data->p.pos.y - obj->pos.y)
		* (data->p.pos.y - obj->pos.y));
	dir.x = (data->p.pos.x - obj->pos.x) / mag;
	dir.y = (data->p.pos.y - obj->pos.y) / mag;
	move_obj(data, dir, obj);
	get_moving_sprite(data, obj);
}
