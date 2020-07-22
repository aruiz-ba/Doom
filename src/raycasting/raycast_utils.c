/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:22:58 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 18:03:45 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	set_dist_and_step(t_raycast *r)
{
	if (r->ray.dir.x < 0)
	{
		r->step.x = -1;
		r->sidedist.x = (r->ray.pos.x - r->m_pos.x) * r->deltadist.x;
	}
	else
	{
		r->step.x = 1;
		r->sidedist.x = (r->m_pos.x + 1.0 - r->ray.pos.x) * r->deltadist.x;
	}
	if (r->ray.dir.y < 0)
	{
		r->step.y = -1;
		r->sidedist.y = (r->ray.pos.y - r->m_pos.y) * r->deltadist.y;
	}
	else
	{
		r->step.y = 1;
		r->sidedist.y = (r->m_pos.y + 1.0 - r->ray.pos.y) * r->deltadist.y;
	}
}

void	get_texturing_values(t_raycast *r, t_data *data)
{
	if (r->side == 0)
	{
		r->walldist = fabs((r->m_pos.x - r->ray.pos.x + (1 - r->step.x) / 2)
				/ r->ray.dir.x);
		r->wall = r->ray.pos.y + r->walldist * r->ray.dir.y;
	}
	else
	{
		r->walldist = fabs((r->m_pos.y - r->ray.pos.y + (1 - r->step.y) / 2)
				/ r->ray.dir.y);
		r->wall = r->ray.pos.x + r->walldist * r->ray.dir.x;
	}
	r->texnum = data->cur_map.map[r->m_pos.x][r->m_pos.y] - 1;
	r->wall -= floor(r->wall);
	r->texw = data->surface[r->texnum]->w;
	r->texh = data->surface[r->texnum]->h;
	r->tex.x = r->wall * r->texh;
	r->lineheight = abs((int)(SCREEN_HEIGHT / r->walldist));
}

short	hit_wall(t_raycast *r, t_data *data)
{
	while (r->hit == 0)
	{
		if (r->sidedist.x < r->sidedist.y)
		{
			r->sidedist.x += r->deltadist.x;
			r->m_pos.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->sidedist.y += r->deltadist.y;
			r->m_pos.y += r->step.y;
			r->side = 1;
		}
		if (data->cur_map.map[r->m_pos.x][r->m_pos.y] == 8)
			return (2);
		else if (data->cur_map.map[r->m_pos.x][r->m_pos.y] > 0)
		{
			r->hit = 1;
			return (1);
		}
	}
	return (0);
}

void	give_draw_values(t_raycast *r, t_data *data)
{
	if (r->lineheight < 0)
		r->lineheight = SCREEN_HEIGHT;
	r->drawstart = -r->lineheight / 2 + (SCREEN_HEIGHT + data->yaw) / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + (SCREEN_HEIGHT + data->yaw) / 2;
	if (r->drawend >= SCREEN_HEIGHT)
		r->drawend = SCREEN_HEIGHT;
	if (r->drawend < 0)
		r->drawend = SCREEN_HEIGHT;
}
