/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:17:04 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 16:41:29 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	print_menu_background(t_data *data, int y_offset)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		j = -1;
		x = ((double)i * 640.0) / (double)SCREEN_WIDTH;
		while (++j < SCREEN_HEIGHT)
		{
			y = ((double)j * 360.0) / (double)SCREEN_HEIGHT;
			data->pixels[i + j * SCREEN_WIDTH] =
				get_pixel(data->surface[12], (int)x, (int)y + y_offset);
		}
	}
}

static void	print_menu_custom(t_data *data)
{
	int		i;
	int		j;
	Uint32	color;

	i = -1;
	while (++i < 458)
	{
		j = -1;
		while (++j < 92)
		{
			color = get_pixel(data->surface[11], i / 2, j / 2);
			if (color != 0)
				data->pixels[(i + 728) + (j + 300) * SCREEN_WIDTH] = color;
		}
	}
}

static void	print_menu_text(t_data *data)
{
	int		i;
	int		j;
	double	x;
	double	y;
	Uint32	color;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		j = -1;
		x = ((double)i * 640.0) / (double)SCREEN_WIDTH;
		while (++j < SCREEN_HEIGHT)
		{
			y = ((double)j * 360.0) / (double)SCREEN_HEIGHT;
			color = get_pixel(data->surface[10], (int)x, (int)y);
			if (color != 0)
				data->pixels[i + j * SCREEN_WIDTH] = color;
		}
	}
	if (data->custom_map)
		print_menu_custom(data);
}

void		menu(t_data *data)
{
	print_menu_background(data, ((int)(data->time / 60) % 20) * 360);
	print_menu_text(data);
	menu_selection(data);
}
