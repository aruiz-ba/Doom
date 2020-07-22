/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:39:53 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/25 16:52:32 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			get_stunned_sprite(t_data *data, t_object *obj)
{
	(void)data;
	obj->current_sprite = obj->first_sprite_walk;
}

void			soul_state_machine(t_data *data, t_object *obj)
{
	static void (*action[4])(t_data *, t_object *) =
	{enemy_death, pathfind, hits_taken, get_stunned_sprite};

	if ((!obj->is_aggro && can_see_player(data, obj) == 1) || obj->hp <= 0)
		obj->is_aggro = 1;
	if (obj->is_aggro)
	{
		if (obj->hp <= 0)
			obj->state = DYING;
		else if (data->time - obj->hl_time < 500)
			obj->state = STUNNED;
		else
			obj->state = (obj->dist_to_player >= 1) ? WALKING : ATTACKING;
		action[obj->state](data, obj);
	}
}

void			imp_state_machine(t_data *data, t_object *obj)
{
	static void (*action[3])(t_data *, t_object *) =
	{enemy_death, pathfind, hits_taken};
	int			dist;

	dist = obj->obj_type == 0 ? 1 : 4;
	if ((!obj->is_aggro && can_see_player(data, obj) == 1) || obj->hp <= 0)
		obj->is_aggro = 1;
	if (obj->is_aggro)
	{
		if (obj->hp <= 0)
			obj->state = DYING;
		else
			obj->state = (obj->dist_to_player >= dist) ? WALKING : ATTACKING;
		action[obj->state](data, obj);
	}
}

void			cast_objects(t_data *data)
{
	t_object	*iterator;

	if (data->obj)
	{
		rollback_object(&(data->obj));
		iterator = data->obj;
		while (iterator)
		{
			objectcaster(data, iterator);
			iterator = iterator->next;
		}
	}
}

void			state_machine(t_data *data)
{
	t_object	*iterator;

	iterator = data->obj;
	if (data->obj)
	{
		rollback_object(&(data->obj));
		get_dist_to_player(data);
		sort_objects(data);
		while (iterator)
		{
			if (iterator->obj_type == 0 || iterator->obj_type == 2)
				imp_state_machine(data, iterator);
			else if (iterator->obj_type == 1)
				soul_state_machine(data, iterator);
			iterator->visible = 0;
			iterator = iterator->next;
		}
	}
}
