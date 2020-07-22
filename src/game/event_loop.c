/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:07:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void		display_hud_or_end_screen(t_data *data)
{
	if (!data->menu && !data->enter_screen
			&& !data->exit_screen && !data->death_screen)
	{
		display_hud(data);
		display_health(data);
		display_ammo_side(data);
	}
	if (data->menu == 0 && count_enemies(data) == 0 && !data->death_screen
			&& data->menu_sel != 3 && (data->p.shot_fired == 0
				&& data->p.selected_weapon != 3))
		data->exit_screen = 1;
}

static void		manage_sdl_events(SDL_Event *e, t_data *data)
{
	if (e->type == SDL_QUIT)
		data->quit = 1;
	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		if (e->button.button == SDL_BUTTON_LEFT)
			data->p.is_firing = 1;
		else if (e->button.button == SDL_BUTTON_RIGHT)
		{
			if (data->p.swap_weapon == 1)
				data->p.selected_weapon =
					(data->p.selected_weapon + 1) % 7;
		}
	}
	if (e->type == SDL_MOUSEBUTTONUP)
		if (e->button.button == SDL_BUTTON_LEFT)
			data->p.is_firing = 0;
}

static void		display_game(t_data *data)
{
	ft_bzero(data->e_zbuffer, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(double));
	state_machine(data);
	thread_center(data);
	item_pickup(data);
	combat(data);
	if (data->toggle_minimap)
		draw_minimap(data);
}

static void		handle_events_and_flashes(t_data *data)
{
	const Uint8	*state;

	state = SDL_GetKeyboardState(NULL);
	if (data->menu)
		handle_menu_input(data, state);
	else if (data->enter_screen || data->exit_screen || data->death_screen)
		handle_text_screen_input(data, state);
	else
		handle_input(data, state);
	red_hit_screen(data);
	green_hp_screen(data);
	blue_hp_screen(data);
	display_hud_keys(data);
}

void			game_loop(t_data *data)
{
	SDL_Event	e;

	while (!data->quit)
	{
		data->time = SDL_GetTicks();
		while (SDL_PollEvent(&e))
			manage_sdl_events(&e, data);
		if (data->menu)
			menu(data);
		else if (data->enter_screen || data->exit_screen || data->death_screen)
			display_story_screen(data);
		else
			display_game(data);
		data->ftime = (SDL_GetTicks() - data->time) / 1000;
		SDL_PumpEvents();
		handle_events_and_flashes(data);
		SDL_UpdateTexture(data->texture, NULL, data->pixels,
				4 * SCREEN_WIDTH);
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		display_hud_or_end_screen(data);
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT) * 4);
	}
}

/*
** print fps : ft_putnbrendl((int)(1.0 / data->ftime));
*/
