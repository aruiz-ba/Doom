/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:47:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/05 18:57:07 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_print_grid(t_fdf *img)
{
	int			x;
	int			y;
	t_pt		start;
	t_pt		end;

	y = -1;
	while (++y <= img->map->y)
	{
		start.x = 0;
		start.y = y;
		end.x = img->map->x;
		end.y = y;
		ft_calculate_grid_coord_and_draw_line(start, end, img, WHITE);
	}
	x = -1;
	while (++x <= img->map->x)
	{
		start.x = x;
		start.y = 0;
		end.x = x;
		end.y = img->map->y;
		ft_calculate_grid_coord_and_draw_line(start, end, img, WHITE);
	}
}
