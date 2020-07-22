/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_map_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:51:49 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:39:51 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	get_map1_values(t_data *data)
{
	data->ceiling = data->maps[0].ceiling;
	data->shaded = data->maps[0].night;
	data->toggle_minimap = 1;
	data->p.dir.x = 1;
	data->p.plane.y = -0.66;
	data->p.hp = 50;
	data->p.armor = 0;
	data->p.bullets = 0;
	data->p.shells = 0;
	data->p.cells = 0;
	data->p.has_fired = 1;
	data->p.is_firing = 0;
}

static void	get_map2_values(t_data *data)
{
	data->ceiling = data->maps[1].ceiling;
	data->shaded = data->maps[1].night;
	data->toggle_minimap = 0;
	data->p.dir.x = 1;
	data->p.plane.y = -0.66;
	data->p.hp = 50;
	data->p.armor = 0;
	data->p.bullets = 0;
	data->p.shells = 0;
	data->p.cells = 0;
}

static void	get_map3_values(t_data *data)
{
	data->ceiling = data->maps[2].ceiling;
	data->shaded = data->maps[2].night;
	data->toggle_minimap = 1;
	data->p.dir.x = 1;
	data->p.plane.y = -0.66;
	data->p.hp = 50;
	data->p.armor = 50;
	data->p.bullets = 20;
	data->p.shells = 5;
	data->p.cells = 0;
}

static void	get_custom_map_values(t_data *data)
{
	data->ceiling = data->maps[3].ceiling;
	data->shaded = data->maps[3].night;
	data->p.dir.x = 1;
	data->p.plane.y = -0.66;
	data->toggle_minimap = 1;
	data->p.hp = 100;
	data->p.armor = 25;
	data->p.bullets = MAX_BULLETS;
	data->p.shells = MAX_SHELLS;
	data->p.cells = MAX_CELLS;
}

void		get_map_values(t_data *data, short selected)
{
	ft_bzero(&(data->p), sizeof(t_player));
	data->yaw = 0;
	data->p.rspeed = 2;
	data->p.walkspeed = 3;
	data->p.sprintspeed = 6;
	if (selected == 0)
		get_map1_values(data);
	if (selected == 1)
		get_map2_values(data);
	if (selected == 2)
		get_map3_values(data);
	if (selected == 3)
		get_custom_map_values(data);
}
