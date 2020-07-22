/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_screen_inputs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:39:53 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/25 16:52:32 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	handle_text_screen_input(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	if (state[SDL_SCANCODE_SPACE])
	{
		if (data->enter_screen)
			data->enter_screen = 0;
		else if (data->exit_screen || data->death_screen)
		{
			free_objects(data);
			data->exit_screen = 0;
			data->death_screen = 0;
			data->menu = 1;
		}
	}
}
