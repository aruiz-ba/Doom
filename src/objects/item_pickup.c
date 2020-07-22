/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_pickup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:38:25 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/25 17:55:22 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static short	key_pickup(t_data *data, t_object **obj)
{
	int		id_stock;

	data->p.key++;
	id_stock = (*obj)->id_key;
	*obj = (*obj)->next;
	remove_object(&(data->obj), id_stock);
	return (1);
}

static short	armor_pickup(t_data *data, t_object **obj)
{
	int		id_stock;

	data->p.armor += 25;
	if (data->p.armor > 100)
		data->p.armor = 100;
	id_stock = (*obj)->id_key;
	*obj = (*obj)->next;
	remove_object(&(data->obj), id_stock);
	data->p_armortime = data->time;
	return (1);
}

static short	health_pickup(t_data *data, t_object **obj)
{
	int		id_stock;

	data->p.hp += 25;
	if (data->p.hp > 100)
		data->p.hp = 100;
	id_stock = (*obj)->id_key;
	*obj = (*obj)->next;
	remove_object(&(data->obj), id_stock);
	data->p_healtime = data->time;
	return (1);
}

static short	picked_up_item(t_data *data, t_object **obj)
{
	if ((*obj)->dist_to_player < 0.5)
	{
		if ((*obj)->obj_type == 4 && data->p.bullets < 200)
			return (bullet_pickup(data, obj));
		else if ((*obj)->obj_type == 5 && data->p.shells < 20)
			return (shell_pickup(data, obj));
		else if ((*obj)->obj_type == 6 && data->p.cells < 100)
			return (cell_pickup(data, obj));
		else if ((*obj)->obj_type == 7 && data->p.hp < 100)
			return (health_pickup(data, obj));
		else if ((*obj)->obj_type == 8 && data->p.armor < 100)
			return (armor_pickup(data, obj));
		else if ((*obj)->obj_type == 9 && data->p.key < 10)
			return (key_pickup(data, obj));
	}
	return (0);
}

void			item_pickup(t_data *data)
{
	t_object	*iterator;

	rollback_object(&(data->obj));
	iterator = data->obj;
	while (iterator)
		if (!picked_up_item(data, &iterator))
			iterator = iterator->next;
}
