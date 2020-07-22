/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowcasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:22:58 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 18:03:45 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	windowcasting(t_data *data)
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
		{
			column_calc(data, &r, pt);
			if (pt.x == SCREEN_WIDTH / 2 && r.texnum == 7
					&& (data->window_dist >= r.walldist
						|| !data->window_dist))
			{
				data->is_window.x = r.m_pos.x;
				data->is_window.y = r.m_pos.y;
				data->window_dist = r.walldist;
			}
		}
	}
}
