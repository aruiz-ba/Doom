/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:55:03 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 16:23:52 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			show_player(t_data *data, t_point length)
{
	t_point		pt1;
	t_point		pt2;
	t_d_point	dir;

	pt1.x = data->p.pos.y * length.x;
	pt1.y = data->p.pos.x * length.y;
	dir.y = data->p.dir.x * 10;
	dir.x = data->p.dir.y * 10;
	drawline(pt1, (t_point){pt1.x + dir.x, pt1.y + dir.y}, data, 0);
	pt2.x = pt1.x + 1;
	pt2.y = pt1.y + 1;
	pt1.x -= 1;
	pt1.y -= 1;
	draw_rect_to_sdl(pt1, pt2, data, 0xff00);
}

void			show_enemies(t_data *data, t_point length)
{
	t_point		pt1;
	t_point		pt2;
	t_object	*iterator;

	iterator = data->obj;
	while (iterator)
	{
		if (iterator->obj_type <= 2)
		{
			pt1.x = iterator->pos.y * length.x;
			pt1.y = iterator->pos.x * length.y;
			pt2.x = pt1.x + 1;
			pt2.y = pt1.y + 1;
			pt1.x -= 1;
			pt1.y -= 1;
			draw_rect_to_sdl(pt1, pt2, data, 0xff0000);
		}
		iterator = iterator->next;
	}
}
