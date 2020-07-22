/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:57:32 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:19:57 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	create_sprites_4(t_data *data)
{
	data->obj_sprite[34] = create_sprites("sprites/enemies/boss_dead_8.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[35] = create_sprites("sprites/enemies/boss_dead_9.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[36] = create_sprites("pics/pillar.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[37] = create_sprites("sprites/pickups/bullets.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[38] = create_sprites("sprites/pickups/shells.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[39] = create_sprites("sprites/pickups/cell.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[40] = create_sprites("sprites/pickups/health_pu.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[41] = create_sprites("sprites/pickups/armor_pu.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[42] = create_sprites("sprites/pickups/key.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[43] = create_sprites("sprites/pickups/hud_key.bmp",
			(t_d_point){1, 1}, data);
}

static void	create_sprites_3(t_data *data)
{
	data->obj_sprite[23] = create_sprites("sprites/enemies/boss_walking_3.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[24] = create_sprites("sprites/enemies/boss_walking_4.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[25] =
		create_sprites("sprites/enemies/boss_attacking_1.bmp",
				(t_d_point){1, 1}, data);
	data->obj_sprite[26] =
		create_sprites("sprites/enemies/boss_attacking_2.bmp",
				(t_d_point){1, 1}, data);
	data->obj_sprite[27] = create_sprites("sprites/enemies/boss_dead_1.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[28] = create_sprites("sprites/enemies/boss_dead_2.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[29] = create_sprites("sprites/enemies/boss_dead_3.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[30] = create_sprites("sprites/enemies/boss_dead_4.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[31] = create_sprites("sprites/enemies/boss_dead_5.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[32] = create_sprites("sprites/enemies/boss_dead_6.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[33] = create_sprites("sprites/enemies/boss_dead_7.bmp",
			(t_d_point){1, 1}, data);
	create_sprites_4(data);
}

static void	create_sprites_2(t_data *data)
{
	data->obj_sprite[12] = create_sprites("sprites/enemies/soul_walking_1.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[13] = create_sprites("sprites/enemies/soul_walking_2.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[14] =
		create_sprites("sprites/enemies/soul_attacking_1.bmp",
				(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[15] =
		create_sprites("sprites/enemies/soul_attacking_2.bmp",
				(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[16] = create_sprites("sprites/enemies/soul_dead_1.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[17] = create_sprites("sprites/enemies/soul_dead_2.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[18] = create_sprites("sprites/enemies/soul_dead_3.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[19] = create_sprites("sprites/enemies/soul_dead_4.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[20] = create_sprites("sprites/enemies/soul_dead_5.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[21] = create_sprites("sprites/enemies/boss_walking_1.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[22] = create_sprites("sprites/enemies/boss_walking_2.bmp",
			(t_d_point){1, 1}, data);
	create_sprites_3(data);
}

void		create_sprites_1(t_data *data)
{
	data->obj_sprite[0] = create_sprites("sprites/enemies/imp_walking_1.bmp",
			(t_d_point){0.75, 0.75}, data);
	data->obj_sprite[1] = create_sprites("sprites/enemies/imp_walking_2.bmp",
			(t_d_point){0.75, 0.75}, data);
	data->obj_sprite[2] = create_sprites("sprites/enemies/imp_walking_3.bmp",
			(t_d_point){0.75, 0.75}, data);
	data->obj_sprite[3] = create_sprites("sprites/enemies/imp_walking_4.bmp",
			(t_d_point){0.75, 0.75}, data);
	data->obj_sprite[4] = create_sprites("sprites/enemies/imp_attacking_1.bmp",
			(t_d_point){0.75, 0.75}, data);
	data->obj_sprite[5] = create_sprites("sprites/enemies/imp_attacking_2.bmp",
			(t_d_point){0.75, 0.75}, data);
	data->obj_sprite[6] = create_sprites("sprites/enemies/imp_attacking_3.bmp",
			(t_d_point){0.75, 0.75}, data);
	data->obj_sprite[7] = create_sprites("sprites/enemies/imp_dead_1.bmp",
			(t_d_point){0.75, 62.0 / 57.0 * 0.75}, data);
	data->obj_sprite[8] = create_sprites("sprites/enemies/imp_dead_2.bmp",
			(t_d_point){0.75, 59.0 / 57.0 * 0.75}, data);
	data->obj_sprite[9] = create_sprites("sprites/enemies/imp_dead_3.bmp",
			(t_d_point){0.75, 54.0 / 57.0 * 0.75}, data);
	data->obj_sprite[10] = create_sprites("sprites/enemies/imp_dead_4.bmp",
			(t_d_point){0.75, 46.0 / 57.0 * 0.75}, data);
	data->obj_sprite[11] = create_sprites("sprites/enemies/imp_dead_5.bmp",
			(t_d_point){0.75, 22.0 / 57.0 * 0.75}, data);
	create_sprites_2(data);
}
