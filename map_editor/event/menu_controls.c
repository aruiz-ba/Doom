/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:31 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/03/10 17:10:05 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			set_mous_loop(t_mouse *mous, int i)
{
	if (i < 19)
		mous->loop = i;
	else
	{
		if ((i - 19) < 2)
			mous->mtime = i - 19;
		else
			mous->mceiling = i - 21;
	}
}

void			ft_menu_event(t_mouse *mous, SDL_Event e)
{
	int			tmx;
	int			tmy;
	int			i;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&tmx, &tmy);
			if (tmx >= 1120 && tmx <= 1355 && tmy >= 120 && tmy <= 680)
			{
				i = ((tmy - 120) / 80) * 3 + ((tmx - 1120) / 80) + 1;
				set_mous_loop(mous, i);
			}
			if (tmy >= 680 && tmy <= 750 && tmx >= 1120 && tmx <= 1190)
				set_mous_loop(mous, 22);
			if (tmx >= 1120 && tmx <= 1320 && tmy >= 760 && tmy <= 760 + 97)
				set_mous_loop(mous, 0);
			if (tmx >= 1120 && tmx <= 1320 && tmy >= 862 && tmy <= 862 + 97)
				set_mous_loop(mous, -1);
		}
	}
}
