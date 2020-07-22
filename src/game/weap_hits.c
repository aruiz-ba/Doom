/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weap_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:13:21 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 16:40:54 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

/*
** 0 : knuckle
** 1 : shotgun
** 2 : plasma
** 3 : chainsaw
** 4 : handgun
** 5 : bfg
** 6 : minigun
*/

short			obj_mid_screen(t_object *obj)
{
	if ((obj->pix_mid_x < SCREEN_WIDTH / 10 * 4)
			|| (obj->pix_mid_x > SCREEN_WIDTH / 10 * 6)
			|| (obj->pix_mid_y < SCREEN_HEIGHT / 10 * 3)
			|| (obj->pix_mid_y > SCREEN_HEIGHT / 10 * 8))
		return (0);
	return (1);
}

static void		deal_damage(t_object *obj, short weapon)
{
	short	damage;

	if (weapon == 0)
		damage = 1;
	if (weapon == 6 || weapon == 3)
		damage = 2;
	if (weapon == 2 || weapon == 4)
		damage = 3;
	if (weapon == 1)
		damage = 10;
	if (weapon == 5)
		damage = 100;
	if (obj->obj_type == 0 || weapon == 5 || obj->obj_type == 2)
	{
		if (obj->hp >= damage)
			obj->hp -= damage;
		else
			obj->hp = 0;
	}
	if (obj->is_aggro == 0)
		obj->is_aggro = 1;
	obj->hl_time = SDL_GetTicks();
}

static short	hitscan(t_data *data, t_object *obj)
{
	if (!obj_mid_screen(obj))
		return (0);
	if ((data->p.selected_weapon == 0 || data->p.selected_weapon == 3)
			&& obj->dist_to_player > 2)
		return (0);
	if (data->p.selected_weapon == 1 && obj->dist_to_player > 7)
		return (0);
	if (data->p.selected_weapon == 2 && obj->dist_to_player > 5)
		return (0);
	if (!obj->visible)
		return (0);
	return (1);
}

void			hits_dealt(t_data *data)
{
	t_object	*iterator;
	t_object	*prev;

	iterator = data->obj;
	while (iterator->next)
		iterator = iterator->next;
	while (iterator)
	{
		prev = iterator->prev;
		if (iterator->obj_type <= 2)
		{
			if (hitscan(data, iterator))
			{
				deal_damage(iterator, data->p.selected_weapon);
				if (data->p.selected_weapon != 5)
					break ;
			}
		}
		iterator = prev;
	}
	data->p.has_fired = 1;
}
