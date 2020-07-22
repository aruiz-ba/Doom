/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcaster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:51:01 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 18:05:00 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			floor_side(t_floorcast *f, t_raycast *r)
{
	if (r->side == 0 && r->ray.dir.x > 0)
	{
		f->floor.x = r->m_pos.x;
		f->floor.y = r->m_pos.y + r->wall;
	}
	else if (r->side == 0 && r->ray.dir.x < 0)
	{
		f->floor.x = r->m_pos.x + 1.0;
		f->floor.y = r->m_pos.y + r->wall;
	}
	else if (r->side == 1 && r->ray.dir.y > 0)
	{
		f->floor.x = r->m_pos.x + r->wall;
		f->floor.y = r->m_pos.y;
	}
	else
	{
		f->floor.x = r->m_pos.x + r->wall;
		f->floor.y = r->m_pos.y + 1.0;
	}
}

void			roofcaster(t_data *data, t_raycast *r, int x)
{
	t_floorcast	f;
	int			y;
	int			color;

	y = r->drawstart;
	f.currentdist = 0;
	floor_side(&f, r);
	while (y >= 0)
	{
		f.currentdist = (double)SCREEN_HEIGHT / -(double)(2 * y
			- (SCREEN_HEIGHT + data->yaw) + 1);
		f.weight = f.currentdist / r->walldist;
		f.currentfloor.x = f.weight * f.floor.x
			+ (1 - f.weight) * data->p.pos.x;
		f.currentfloor.y = f.weight * f.floor.y
			+ (1 - f.weight) * data->p.pos.y;
		f.floortex.x = (int)(f.currentfloor.x * 64) % 64;
		f.floortex.y = (int)(f.currentfloor.y * 64) % 64;
		color = (get_pixel(data->surface[4], f.floortex.x, f.floortex.y));
		if (data->pixels[x + y * SCREEN_WIDTH] == 0)
			data->pixels[x + y * SCREEN_WIDTH] = shaded_color(data, color,
														f.currentdist, NULL);
		y--;
	}
}

void			floorcaster(t_data *data, t_raycast *r, int x)
{
	t_floorcast	f;
	int			y;
	int			color;

	y = r->drawend - 1;
	f.currentdist = 0;
	floor_side(&f, r);
	while (++y < SCREEN_HEIGHT)
	{
		f.currentdist = (double)SCREEN_HEIGHT / (double)(2 * y
			- (SCREEN_HEIGHT + data->yaw) + 1);
		f.weight = f.currentdist / r->walldist;
		f.currentfloor.x = f.weight * f.floor.x
			+ (1 - f.weight) * data->p.pos.x;
		f.currentfloor.y = f.weight * f.floor.y
			+ (1 - f.weight) * data->p.pos.y;
		f.floortex.x = (int)(f.currentfloor.x * 64) % 64;
		f.floortex.y = (int)(f.currentfloor.y * 64) % 64;
		color = (get_pixel(data->surface[3], f.floortex.x, f.floortex.y));
		if (data->pixels[x + y * SCREEN_WIDTH] == 0)
			data->pixels[x + y * SCREEN_WIDTH] = shaded_color(data, color,
														f.currentdist, NULL);
	}
}
