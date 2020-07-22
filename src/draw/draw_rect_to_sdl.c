/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_to_sdl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:16:31 by jmoucach          #+#    #+#             */
/*   Updated: 2020/02/26 12:49:23 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	draw_rect_to_sdl(t_point pt_one, t_point pt_two,
			t_data *data, int colour)
{
	t_point start_point;
	t_point end_point;

	start_point.x = (pt_one.x < pt_two.x ? pt_one.x : pt_two.x);
	start_point.y = (pt_one.y < pt_two.y ? pt_one.y : pt_two.y);
	end_point.x = (pt_one.x > pt_two.x ? pt_one.x : pt_two.x);
	end_point.y = (pt_one.y > pt_two.y ? pt_one.y : pt_two.y);
	while (start_point.y++ < end_point.y)
	{
		drawline(start_point, (t_point){end_point.x, start_point.y},
			data, colour);
	}
}
