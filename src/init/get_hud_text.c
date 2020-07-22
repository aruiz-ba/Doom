/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hud_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:25:39 by acostaz           #+#    #+#             */
/*   Updated: 2020/04/17 17:51:38 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void				get_infinite_text(t_data *data)
{
	if (!(get_hud_text(data, "INFINITE", &(data->hud.infinite_text))))
		clean_exit(data, "Infinite text malloc error");
}

short				get_hud_text(t_data *data, char *text, SDL_Texture **tex)
{
	SDL_Surface		*tmp;
	short			return_value;

	return_value = 1;
	if (tex)
	{
		if (*text)
			SDL_DestroyTexture(*tex);
		tmp = TTF_RenderText_Solid(data->hud.font, text, data->hud.text_color);
		if (!(*tex = SDL_CreateTextureFromSurface(data->renderer, tmp)))
			return_value = 0;
		SDL_FreeSurface(tmp);
	}
	return (return_value);
}
