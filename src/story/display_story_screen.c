/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_story_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:39:53 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/25 16:52:32 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	display_one_screen(t_data *data, short screen)
{
	int		i;
	int		j;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT)
		{
			data->pixels[i + j * SCREEN_WIDTH] =
				get_pixel(data->surface[screen], i / 2, j / 2);
		}
	}
}

void		display_story_screen(t_data *data)
{
	if (data->death_screen)
		display_one_screen(data, 14);
	if (data->enter_screen)
	{
		if (data->menu_sel == 0)
			display_one_screen(data, 15);
		else if (data->menu_sel == 1)
			display_one_screen(data, 16);
		else if (data->menu_sel == 2)
			display_one_screen(data, 17);
	}
	if (data->exit_screen)
	{
		if (data->menu_sel == 0)
			display_one_screen(data, 18);
		else if (data->menu_sel == 1)
			display_one_screen(data, 19);
		else if (data->menu_sel == 2)
			display_one_screen(data, 20);
	}
}
