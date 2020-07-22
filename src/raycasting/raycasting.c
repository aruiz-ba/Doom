/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:22:58 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 18:03:45 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	cast_one_pixel(t_data *data, t_raycast *r, t_point pt)
{
	r->tex.y = (pt.y * 2 - (SCREEN_HEIGHT + data->yaw) + r->lineheight)
		* (r->texh / 2) / (r->lineheight + 1);
	r->color = get_pixel(data->surface[r->texnum],
			r->tex.x, r->tex.y);
	if (data->pixels[pt.x + pt.y * SCREEN_WIDTH] == 0
			|| (r->texnum == 7 && r->color != 0
				&& (r->walldist < data->e_zbuffer[pt.x + pt.y * SCREEN_WIDTH]
					|| data->e_zbuffer[pt.x + pt.y * SCREEN_WIDTH] == 0)))
		data->pixels[pt.x + pt.y * SCREEN_WIDTH] = shaded_color(data,
				r->color, r->walldist, NULL);
	if (r->texnum == 7 && pt.x == SCREEN_WIDTH / 2
			&& pt.y > SCREEN_HEIGHT / 10 * 3 && pt.y < SCREEN_HEIGHT / 10 * 8)
		data->hit_window = 1;
}

void	column_calc(t_data *data, t_raycast *r, t_point pt)
{
	get_texturing_values(r, data);
	give_draw_values(r, data);
	pt.y = r->drawstart - 1;
	while (++pt.y <= r->drawend && is_in_frame(pt))
		cast_one_pixel(data, r, pt);
}

void	raycasting(t_data *data)
{
	t_raycast	r;
	t_point		pt;
	int			end;

	pt.x = which_thread(data) * (SCREEN_WIDTH / NB_THREAD) - 1;
	end = pt.x + 1 + (SCREEN_WIDTH / NB_THREAD);
	while (++pt.x < end)
	{
		set_raycast_values(&r, data->p, pt.x);
		set_dist_and_step(&r);
		while (hit_wall(&r, data) == 2)
			;
		column_calc(data, &r, pt);
		data->zbuffer[pt.x] = r.walldist;
		floorcaster(data, &r, pt.x);
		if (data->ceiling)
			roofcaster(data, &r, pt.x);
		else
			print_skybox(data, &r, pt.x);
	}
}
