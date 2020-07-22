/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:38:39 by jmoucach          #+#    #+#             */
/*   Updated: 2020/04/17 17:45:21 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void				display_bullets_side(t_data *data)
{
	static short	old_bullets = MAX_BULLETS + 1;
	int				w;
	int				h;
	char			*str;
	SDL_Rect		rect;

	if (data->p.bullets != old_bullets || data->hud.bullets_text)
	{
		old_bullets = data->p.bullets;
		if (!(str = ft_itoa(data->p.bullets)))
			clean_exit(data, "Text malloc error");
		if (!(get_hud_text(data, str, &(data->hud.bullets_text))))
		{
			free(str);
			clean_exit(data, "Get text error");
		}
		free(str);
	}
	SDL_QueryTexture(data->hud.bullets_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 290 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 22, w / 2, h / 2};
	SDL_RenderCopy(data->renderer, data->hud.bullets_text, NULL, &rect);
}

void				display_shells_side(t_data *data)
{
	static short	old_shells = MAX_SHELLS + 1;
	int				w;
	int				h;
	char			*str;
	SDL_Rect		rect;

	if (data->p.shells != old_shells || !data->hud.shells_text)
	{
		old_shells = data->p.shells;
		if (!(str = ft_itoa(data->p.shells)))
			clean_exit(data, "Text malloc error");
		if (!(get_hud_text(data, str, &(data->hud.shells_text))))
		{
			free(str);
			clean_exit(data, "Get text error");
		}
		free(str);
	}
	SDL_QueryTexture(data->hud.shells_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 290 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 50, w / 2, h / 2};
	SDL_RenderCopy(data->renderer, data->hud.shells_text, NULL, &rect);
}

void				display_cells_side(t_data *data)
{
	static short	old_cells = MAX_CELLS + 1;
	int				w;
	int				h;
	char			*str;
	SDL_Rect		rect;

	if (data->p.cells != old_cells || !data->hud.cells_text)
	{
		old_cells = data->p.cells;
		if (!(str = ft_itoa(data->p.cells)))
			clean_exit(data, "Text malloc error");
		if (!(get_hud_text(data, str, &(data->hud.cells_text))))
		{
			free(str);
			clean_exit(data, "Get text error");
		}
		free(str);
	}
	SDL_QueryTexture(data->hud.cells_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 290 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 105, w / 2, h / 2};
	SDL_RenderCopy(data->renderer, data->hud.cells_text, NULL, &rect);
}

void				display_current_ammo(t_data *data, short id)
{
	SDL_Rect		rect;
	int				w;
	int				h;

	if (id == 0 || id == 3)
	{
		data->hud.ammo_text = data->hud.infinite_text;
		w = 120;
		h = 60;
		rect = (SDL_Rect){SCREEN_WIDTH * 24 / 320 - w / 2,
			SCREEN_HEIGHT * 0.8 + 14, w, h};
	}
	else
	{
		if (id == 1)
			data->hud.ammo_text = data->hud.shells_text;
		else if (id == 2 || id == 5)
			data->hud.ammo_text = data->hud.cells_text;
		else if (id == 4 || id == 6)
			data->hud.ammo_text = data->hud.bullets_text;
		SDL_QueryTexture(data->hud.ammo_text, NULL, NULL, &w, &h);
		rect = (SDL_Rect){SCREEN_WIDTH * 27 / 320 - w / 2,
			SCREEN_HEIGHT * 0.8 + 14, w, h};
	}
	SDL_RenderCopy(data->renderer, data->hud.ammo_text, NULL, &rect);
}

void				display_ammo_side(t_data *data)
{
	display_bullets_side(data);
	display_shells_side(data);
	display_cells_side(data);
	display_current_ammo(data, data->p.selected_weapon);
}
