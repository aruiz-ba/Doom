/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:51:25 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:07:27 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	nullify_tab(void **tab, int size)
{
	int i;

	i = -1;
	while (++i < size)
		tab[i] = NULL;
}

void	nullify_sprites(t_sprite *sprites, int size)
{
	int i;

	i = -1;
	while (++i < size)
		sprites[i].surf = NULL;
}

void	nullify_mallocs(t_data *data)
{
	data->window = NULL;
	data->renderer = NULL;
	data->texture = NULL;
	data->surface = NULL;
	data->obj_sprite = NULL;
	data->sprites = NULL;
	data->weapon_texture = NULL;
	data->pixels = NULL;
	data->maps[0].map = NULL;
	data->maps[1].map = NULL;
	data->maps[2].map = NULL;
	data->maps[3].map = NULL;
	data->cur_map.map = NULL;
	data->zbuffer = NULL;
	data->e_zbuffer = NULL;
	data->obj = NULL;
	data->hud.font = NULL;
	data->hud.hud_texture = NULL;
	data->hud.face_texture = NULL;
	data->hud.hp_text = NULL;
	data->hud.bullets_text = NULL;
	data->hud.shells_text = NULL;
	data->hud.cells_text = NULL;
	data->hud.infinite_text = NULL;
	data->hud.ammo_text = NULL;
}
