/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:07:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void		handle_input2(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_M] || data->p.hp <= 0)
	{
		if (data->p.hp > 0)
			data->menu = 1;
		else
			data->death_screen = 1;
		data->p.key = 0;
		free_objects(data);
	}
	if (state[SDL_SCANCODE_KP_PLUS])
		if (data->mouse_sens < 2.0)
			data->mouse_sens += 0.1;
	if (state[SDL_SCANCODE_KP_MINUS])
		if (data->mouse_sens > 0.5)
			data->mouse_sens -= 0.1;
	if (state[SDL_SCANCODE_E])
		check_doors(data);
}

void			handle_input(t_data *data, const Uint8 *state)
{
	SDL_GetRelativeMouseState(&(data->mouse.x), &(data->mouse.y));
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S])
		walk(data, state[SDL_SCANCODE_W] - state[SDL_SCANCODE_S],
				state[SDL_SCANCODE_LSHIFT]);
	if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_A])
		strafe(data, state[SDL_SCANCODE_D] - state[SDL_SCANCODE_A],
				state[SDL_SCANCODE_LSHIFT]);
	rotate(data);
	look_up_down(data);
	handle_input2(data, state);
}
