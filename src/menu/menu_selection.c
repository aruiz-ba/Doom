/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:17:04 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 16:41:29 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void		print_menu_arrow(t_data *data, t_point offset)
{
	int		i;
	int		j;
	Uint32	color;

	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < 30)
		{
			color = get_pixel(data->surface[13], i, j);
			if (color != 0)
				data->pixels[i + offset.x
					+ (j + offset.y) * SCREEN_WIDTH] = color;
		}
	}
}

static t_point	get_arrow_coords(t_data *data)
{
	t_point		coords;

	if (data->menu_sel == 0 || data->menu_sel == 1 || data->menu_sel == 2)
		coords.x = 100;
	if (data->menu_sel == 0)
		coords.y = 285;
	if (data->menu_sel == 1)
		coords.y = 405;
	if (data->menu_sel == 2)
		coords.y = 530;
	if (data->menu_sel == 3)
	{
		coords.x = 680;
		coords.y = 320;
	}
	if (data->menu_sel == 4)
	{
		coords.x = 690;
		coords.y = 490;
	}
	return (coords);
}

void			menu_selection(t_data *data)
{
	print_menu_arrow(data, get_arrow_coords(data));
}
