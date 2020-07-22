/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:39:58 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 18:06:28 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			get_attacking_sprite(t_data *data, t_object *obj)
{
	obj->lastupdate += data->ftime;
	if (obj->current_sprite < obj->first_sprite_attack
					|| obj->current_sprite > obj->first_sprite_attack
					+ obj->num_of_sprites_attack)
	{
		obj->lastupdate = 0;
		obj->current_sprite = obj->first_sprite_attack;
	}
	else if (obj->lastupdate >= 0.5 / obj->num_of_sprites_attack)
	{
		obj->lastframe++;
		obj->lastframe %= obj->num_of_sprites_attack;
		obj->lastupdate = 0;
		obj->current_sprite = obj->first_sprite_attack + obj->lastframe;
	}
}

void			hits_taken(t_data *data, t_object *obj)
{
	get_attacking_sprite(data, obj);
	if (obj->current_sprite == obj->first_sprite_attack
					+ obj->num_of_sprites_attack - 1
					&& data->time - data->p_dmgtime > 500)
	{
		data->p_dmgtime = data->time;
		data->p.hp -= data->p.armor > 5 ? 0 : 5 - data->p.armor;
		data->p.armor = data->p.armor > 5 ? data->p.armor - 5 : 0;
	}
}

static short	window_to_break(t_data *data)
{
	t_object	*iterator;

	if (data->is_window.x == 0 && data->is_window.y == 0)
		return (0);
	rollback_object(&(data->obj));
	iterator = data->obj;
	while (iterator)
	{
		if (iterator->dist_to_player < data->window_dist
				&& obj_mid_screen(iterator) && iterator->visible)
			return (0);
		iterator = iterator->next;
	}
	if (data->hit_window && !(data->p.selected_weapon == 0
				|| data->p.selected_weapon == 3
				|| (data->p.selected_weapon == 1 && data->window_dist > 7)
				|| (data->p.selected_weapon == 2 && data->window_dist > 5)))
	{
		data->cur_map.map[data->is_window.x][data->is_window.y] = 0;
		ft_bzero(&(data->is_window), sizeof(t_point));
		data->window_dist = 0;
		data->p.has_fired = 1;
		return (1);
	}
	return (0);
}

void			combat(t_data *data)
{
	data->p.swap_weapon = use_weapon(data, data->p.selected_weapon);
	if (!data->p.has_fired)
		if (!window_to_break(data))
			if (data->obj)
				hits_dealt(data);
}
