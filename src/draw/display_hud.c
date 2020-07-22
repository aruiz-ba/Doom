/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:10:42 by jmoucach          #+#    #+#             */
/*   Updated: 2020/02/28 02:50:47 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			display_hud(t_data *data)
{
	SDL_Rect	dstrect;
	int			h;
	int			w;

	SDL_QueryTexture(data->weapon_texture, NULL, NULL, &w, &h);
	dstrect = (SDL_Rect){SCREEN_WIDTH / 2 - w, SCREEN_HEIGHT * 0.8 - 2 * h,
		2 * w, 2 * h};
	SDL_RenderCopy(data->renderer, data->weapon_texture, NULL, &dstrect);
	SDL_RenderCopy(data->renderer, data->hud.hud_texture, NULL,
		&(data->hud.hud_pos));
	SDL_RenderCopy(data->renderer, data->hud.face_texture, NULL,
		&(data->hud.face_pos));
}
