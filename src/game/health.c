/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:44:16 by jmoucach          #+#    #+#             */
/*   Updated: 2020/04/17 17:54:31 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void				display_armor(t_data *data)
{
	static short	old_armor = MAX_ARMOR + 1;
	int				w;
	int				h;
	char			*str;
	SDL_Rect		rect;

	if (data->p.armor != old_armor || data->hud.armor_text)
	{
		old_armor = data->p.armor;
		if (!(str = ft_itoa(data->p.armor)))
			clean_exit(data, "Text malloc error");
		if (!(get_hud_text(data, str, &(data->hud.armor_text))))
		{
			free(str);
			clean_exit(data, "Get text error");
		}
		free(str);
	}
	SDL_QueryTexture(data->hud.armor_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 208 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 10, w, h};
	SDL_RenderCopy(data->renderer, data->hud.armor_text, NULL, &rect);
}

void				display_health(t_data *data)
{
	static short	old_hp = MAX_HEALTH + 1;
	int				w;
	int				h;
	char			*str;
	SDL_Rect		rect;

	if (data->p.hp != old_hp || data->hud.hp_text)
	{
		old_hp = data->p.hp;
		if (!(str = ft_itoa(data->p.hp)))
			clean_exit(data, "Text malloc error");
		if (!(get_hud_text(data, str, &(data->hud.hp_text))))
		{
			free(str);
			clean_exit(data, "Get text error");
		}
		free(str);
	}
	SDL_QueryTexture(data->hud.hp_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 74 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 10, w, h};
	SDL_RenderCopy(data->renderer, data->hud.hp_text, NULL, &rect);
	display_armor(data);
}
