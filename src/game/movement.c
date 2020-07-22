/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:14:45 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 16:00:54 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void		look_up_down(t_data *data)
{
	data->yaw -= data->mouse.y * 3 * data->mouse_sens;
	if (data->yaw > SCREEN_HEIGHT - 1)
		data->yaw = SCREEN_HEIGHT - 1;
	if (data->yaw < -SCREEN_HEIGHT + 1)
		data->yaw = -SCREEN_HEIGHT + 1;
}

void		rotate(t_data *data)
{
	double	olddir;
	double	oldplane;
	double	diffx;

	diffx = (-(double)data->mouse.x / 40) * data->mouse_sens;
	if (data->mouse.x != 0)
	{
		oldplane = data->p.plane.x;
		olddir = data->p.dir.x;
		data->p.dir.x = data->p.dir.x
			* cos(diffx * data->p.rspeed * data->ftime)
			- data->p.dir.y * sin(diffx * data->p.rspeed * data->ftime);
		data->p.dir.y = olddir * sin(diffx * data->p.rspeed * data->ftime)
			+ data->p.dir.y * cos(diffx * data->p.rspeed * data->ftime);
		data->p.plane.x = data->p.plane.x
			* cos(diffx * data->p.rspeed * data->ftime) - data->p.plane.y
			* sin(diffx * data->p.rspeed * data->ftime);
		data->p.plane.y = oldplane * sin(diffx * data->p.rspeed * data->ftime)
			+ data->p.plane.y * cos(diffx * data->p.rspeed * data->ftime);
	}
}

void		walk(t_data *data, int walkdir, int sprint)
{
	double	dx;
	double	dy;
	double	speed;

	speed = sprint ? data->p.sprintspeed : data->p.walkspeed;
	dx = walkdir * data->p.dir.x * speed * data->ftime;
	dy = walkdir * data->p.dir.y * speed * data->ftime;
	if (data->cur_map.map[(int)(data->p.pos.x + dx)]
			[(int)data->p.pos.y] == 0)
		data->p.pos.x += dx;
	if (data->cur_map.map[(int)(data->p.pos.x)]
			[(int)(data->p.pos.y + dy)] == 0)
		data->p.pos.y += dy;
}

void		strafe(t_data *data, int strafe, int sprint)
{
	double	dx;
	double	dy;
	double	speed;

	speed = sprint ? data->p.sprintspeed : data->p.walkspeed;
	dx = strafe * data->p.dir.y * speed * data->ftime * 0.7;
	dy = -strafe * data->p.dir.x * speed * data->ftime * 0.7;
	if (data->cur_map.map[(int)(data->p.pos.x + dx)]
			[(int)data->p.pos.y] == 0)
		data->p.pos.x += dx;
	if (data->cur_map.map[(int)(data->p.pos.x)]
			[(int)(data->p.pos.y + dy)] == 0)
		data->p.pos.y += dy;
}
