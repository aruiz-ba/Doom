/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:38:23 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/08 20:09:48 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			set_light_ceiling(int time, int ceiling, t_fdf *img)
{
	if (time == 0 && ceiling == 1)
		img->map->light_ceiling = 0;
	if (time == 1 && ceiling == 1)
		img->map->light_ceiling = 1;
	if (time == 0 && ceiling == 0)
		img->map->light_ceiling = 2;
	if (time == 1 && ceiling == 0)
		img->map->light_ceiling = 3;
}

void			ft_mouse_event(t_fdf *img, t_mouse *mous, SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			if (mous->loop == -1)
			{
				set_light_ceiling(mous->mtime, mous->mceiling, img);
				ft_save_map(img);
			}
			else
				click_to_modify_map(img->map, mous);
		}
	}
}
