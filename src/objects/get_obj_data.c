/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 01:43:38 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 15:15:44 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			get_obj_data_0(t_object **obj)
{
	(*obj)->move_speed = 0;
	(*obj)->first_sprite_walk = 1;
	(*obj)->num_of_sprites_walk = 1;
	(*obj)->first_sprite_attack = 1;
	(*obj)->num_of_sprites_attack = 1;
	(*obj)->first_sprite_death = 1;
	(*obj)->num_of_sprites_death = 1;
	(*obj)->current_sprite = (*obj)->obj_type + 33;
	(*obj)->sprite_pos = GROUND;
}

void			get_obj_data_1(t_object **obj)
{
	(*obj)->move_speed = 1;
	(*obj)->first_sprite_walk = 0;
	(*obj)->num_of_sprites_walk = 4;
	(*obj)->first_sprite_attack = 4;
	(*obj)->num_of_sprites_attack = 3;
	(*obj)->first_sprite_death = 7;
	(*obj)->num_of_sprites_death = 5;
	(*obj)->current_sprite = (*obj)->first_sprite_walk + 1;
	(*obj)->sprite_pos = GROUND;
	(*obj)->state = IDLE;
}

void			get_obj_data_2(t_object **obj)
{
	(*obj)->move_speed = 1;
	(*obj)->first_sprite_walk = 12;
	(*obj)->num_of_sprites_walk = 2;
	(*obj)->first_sprite_attack = 14;
	(*obj)->num_of_sprites_attack = 2;
	(*obj)->first_sprite_death = 16;
	(*obj)->num_of_sprites_death = 5;
	(*obj)->current_sprite = (*obj)->first_sprite_walk + 1;
	(*obj)->sprite_pos = FLOAT;
	(*obj)->state = IDLE;
}

void			get_obj_data_3(t_object **obj)
{
	(*obj)->move_speed = 1;
	(*obj)->first_sprite_walk = 21;
	(*obj)->num_of_sprites_walk = 4;
	(*obj)->first_sprite_attack = 25;
	(*obj)->num_of_sprites_attack = 2;
	(*obj)->first_sprite_death = 27;
	(*obj)->num_of_sprites_death = 9;
	(*obj)->current_sprite = (*obj)->first_sprite_walk + 1;
	(*obj)->hp = 100;
	(*obj)->sprite_pos = GROUND;
	(*obj)->state = IDLE;
}
