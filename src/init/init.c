/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:57:11 by jmoucach          #+#    #+#             */
/*   Updated: 2020/04/17 17:53:30 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void		create_renderer_texture_and_pixels(t_data *data)
{
	if (!(data->renderer = SDL_CreateRenderer(data->window, -1, 0)))
		clean_exit(data, (char*)SDL_GetError());
	else if (!(data->texture = SDL_CreateTexture(data->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH,
		SCREEN_HEIGHT)))
		clean_exit(data, (char*)SDL_GetError());
	else if (!(data->pixels = (Uint32 *)malloc(sizeof(Uint32) * SCREEN_WIDTH
					* SCREEN_HEIGHT + 1)))
		clean_exit(data, "Pixel array malloc error");
}

void		prepare_hud(t_data *data)
{
	if (TTF_Init() == -1)
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->hud.font = TTF_OpenFont("fonts/DooM.ttf", 50)))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->hud.hud_texture = loadimage_hud(data, "sprites/hud_bar.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	data->hud.hud_pos = (SDL_Rect){0, SCREEN_HEIGHT * 0.8,
											SCREEN_WIDTH, 0.2 * SCREEN_HEIGHT};
	if (!(data->hud.face_texture = loadimage_hud(data,
												"sprites/doom_guy_face.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	data->hud.face_pos = (SDL_Rect){SCREEN_WIDTH / 2 - 50,
						SCREEN_HEIGHT * 0.8 + 5, 100, 0.2 * SCREEN_HEIGHT - 5};
	data->hud.text_color.r = 211;
	data->hud.text_color.g = 2;
	data->hud.text_color.b = 4;
	data->hud.text_color.a = 255;
	get_infinite_text(data);
}

void		set_raycast_values(t_raycast *values, t_player player, int x)
{
	values->camera = 2 * x / (double)SCREEN_WIDTH - 1;
	values->ray.pos.x = player.pos.x;
	values->ray.pos.y = player.pos.y;
	values->ray.dir.x = player.dir.x + player.plane.x * values->camera;
	values->ray.dir.y = player.dir.y + player.plane.y * values->camera;
	values->m_pos.x = (int)values->ray.pos.x;
	values->m_pos.y = (int)values->ray.pos.y;
	values->deltadist.x = sqrt(1 + (values->ray.dir.y * values->ray.dir.y)
		/ (values->ray.dir.x * values->ray.dir.x));
	values->deltadist.y = sqrt(1 + (values->ray.dir.x * values->ray.dir.x)
		/ (values->ray.dir.y * values->ray.dir.y));
	values->hit = 0;
	values->side = 0;
}

t_sprite	create_sprites(char *path, t_d_point scale, t_data *data)
{
	t_sprite	sprite;

	if (!(sprite.surf = loadimage(path)))
		clean_exit(data, (char*)SDL_GetError());
	sprite.scale.x = scale.x;
	sprite.scale.y = scale.y;
	return (sprite);
}

void		init(t_data *data)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		clean_exit(data, (char*)SDL_GetError());
	else
	{
		data->window = SDL_CreateWindow("Doom-Nukem", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);
		if (data->window)
			create_renderer_texture_and_pixels(data);
		else
			clean_exit(data, (char*)SDL_GetError());
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}
}
