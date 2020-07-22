/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:57:32 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:19:57 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	alloc_data_structs(t_data *data)
{
	if (!(data->surface = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 21)))
		clean_exit(data, "Surface malloc error");
	nullify_tab((void**)data->surface, 21);
	if (!(data->obj_sprite = (t_sprite*)malloc(sizeof(t_sprite) * 44)))
		clean_exit(data, "Object sprite malloc error");
	nullify_sprites(data->obj_sprite, 44);
	if (!(data->zbuffer = (double *)malloc(sizeof(double) * SCREEN_WIDTH)))
		clean_exit(data, "ZBuffer malloc error");
	if (!(data->e_zbuffer = (double *)malloc(sizeof(double)
					* SCREEN_WIDTH * SCREEN_HEIGHT)))
		clean_exit(data, "Enemy ZBuffer malloc error");
	if (!(data->sprites = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * 33)))
		clean_exit(data, "Sprites malloc error");
	nullify_tab((void**)data->sprites, 33);
}

void		set_values(t_data *data, int argc)
{
	ft_bzero(data, sizeof(t_data));
	nullify_mallocs(data);
	data->custom_map = (argc == 1) ? 0 : 1;
	data->p.dir.x = 1;
	data->toggle_minimap = 1;
	data->p.plane.y = -0.66;
	data->p.rspeed = 2;
	data->p.sprintspeed = 6;
	data->p.walkspeed = 3;
	data->p.hp = 100;
	data->p.armor = 25;
	data->p.bullets = MAX_BULLETS;
	data->p.shells = MAX_SHELLS;
	data->p.rockets = 0;
	data->p.cells = MAX_CELLS;
	data->p.has_fired = 1;
	data->mouse_sens = 1;
	data->menu = 1;
	alloc_data_structs(data);
	create_sprites_1(data);
}
