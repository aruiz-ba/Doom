/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_vision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:38:27 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/25 16:43:25 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	vision_step(t_d_point *sidedist, t_d_point deltadist,
		t_point *m_pos, t_point step)
{
	if (sidedist->x < sidedist->y)
	{
		sidedist->x += deltadist.x;
		m_pos->x += step.x;
	}
	else
	{
		sidedist->y += deltadist.y;
		m_pos->y += step.y;
	}
}

static void	get_sidedist_values(t_ray ray, t_d_point *sidedist,
		t_d_point deltadist, t_point m_pos)
{
	if (ray.dir.x < 0)
		sidedist->x = (ray.pos.x - m_pos.x) * deltadist.x;
	else
		sidedist->x = (m_pos.x + 1.0 - ray.pos.x) * deltadist.x;
	if (ray.dir.y < 0)
		sidedist->y = (ray.pos.y - m_pos.y) * deltadist.y;
	else
		sidedist->y = (m_pos.y + 1.0 - ray.pos.y) * deltadist.y;
}

static void	get_ray_pos_values(t_data *data, t_object *obj,
		t_ray *ray, t_point *m_pos)
{
	ray->pos.x = obj->pos.x;
	ray->pos.y = obj->pos.y;
	ray->dir.x = data->p.pos.x - obj->pos.x;
	ray->dir.y = data->p.pos.y - obj->pos.y;
	m_pos->x = (int)obj->pos.x;
	m_pos->y = (int)obj->pos.y;
}

short		can_see_player(t_data *data, t_object *obj)
{
	t_ray		ray;
	t_point		m_pos;
	t_d_point	deltadist;
	t_d_point	sidedist;
	t_point		step;

	if (obj->dist_to_player > 10)
		return (0);
	get_ray_pos_values(data, obj, &ray, &m_pos);
	deltadist.x = sqrt(1 + (ray.dir.y * ray.dir.y) / (ray.dir.x * ray.dir.x));
	deltadist.y = sqrt(1 + (ray.dir.x * ray.dir.x) / (ray.dir.y * ray.dir.y));
	get_sidedist_values(ray, &sidedist, deltadist, m_pos);
	step.x = ray.dir.x < 0 ? -1 : 1;
	step.y = ray.dir.y < 0 ? -1 : 1;
	while (m_pos.x >= 0 && m_pos.x < data->cur_map.height
			&& m_pos.y >= 0 && m_pos.y < data->cur_map.width)
	{
		vision_step(&sidedist, deltadist, &m_pos, step);
		if (data->cur_map.map[m_pos.x][m_pos.y] > 0)
			return (0);
		if (m_pos.x == (int)data->p.pos.x && m_pos.y == (int)data->p.pos.y)
			return (1);
	}
	return (1);
}
