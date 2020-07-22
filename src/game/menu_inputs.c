/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:39:53 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/25 16:52:32 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void		move_arrow_2(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_A] && !data->has_menued)
		if (data->menu_sel == 3 || data->menu_sel == 4)
		{
			data->menu_sel -= data->menu_sel == 3 ? 3 : 2;
			data->has_menued = 1;
		}
	if (state[SDL_SCANCODE_D] && !data->has_menued)
	{
		if (data->menu_sel == 0 || data->menu_sel == 1)
		{
			data->menu_sel = data->custom_map ? 3 : 4;
			data->has_menued = 1;
		}
		if (data->menu_sel == 2)
		{
			data->menu_sel = 4;
			data->has_menued = 1;
		}
	}
}

static void		move_arrow_1(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_W] && !data->has_menued)
		if (data->menu_sel == 1 || data->menu_sel == 2
				|| (data->menu_sel == 4 && data->custom_map))
		{
			data->menu_sel--;
			data->has_menued = 1;
		}
	if (state[SDL_SCANCODE_S] && !data->has_menued)
		if (data->menu_sel == 0 || data->menu_sel == 1 || data->menu_sel == 3)
		{
			data->menu_sel++;
			data->has_menued = 1;
		}
}

void			handle_menu_input(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	move_arrow_1(data, state);
	move_arrow_2(data, state);
	if (data->has_menued && !state[SDL_SCANCODE_W] && !state[SDL_SCANCODE_S]
			&& !state[SDL_SCANCODE_A] && !state[SDL_SCANCODE_D])
		data->has_menued = 0;
	if (state[SDL_SCANCODE_RETURN] || state[SDL_SCANCODE_KP_ENTER])
	{
		if (data->menu_sel == 4)
			data->quit = 1;
		else
		{
			delete_cur_map(data);
			if (!copy_cur_map(data))
				clean_exit(data, "cur map malloc error");
			get_map_values(data, data->menu_sel);
			fill_map(data, data->maps[data->menu_sel]);
			data->menu = 0;
			data->enter_screen = data->menu_sel + 1;
			if (data->menu_sel == 3)
				data->enter_screen = 0;
		}
	}
}
