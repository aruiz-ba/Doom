/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:42:14 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 16:51:44 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

Uint32			get_pixel(SDL_Surface *s, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = s->format->BytesPerPixel;
	p = s->pixels + y * s->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16*)p);
	else if (bpp == 3)
		return ((p[0]) | (p[1] << 8) | (p[2] << 16));
	else
		return (*(Uint32*)p);
}

SDL_Surface		*loadimage(char *path)
{
	SDL_Surface *loadedsurface;

	loadedsurface = SDL_LoadBMP(path);
	if (!loadedsurface)
		return (NULL);
	return (loadedsurface);
}

void			load_menu(t_data *data)
{
	if (!(data->surface[10] = loadimage("pics/menu/menu_titles.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[11] = loadimage("pics/menu/menu_custom.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[12] = loadimage("pics/menu/menu_background.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[13] = loadimage("pics/menu/menu_arrow.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[14] = loadimage("pics/story/dead.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[15] = loadimage("pics/story/start1.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[16] = loadimage("pics/story/start2.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[17] = loadimage("pics/story/start3.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[18] = loadimage("pics/story/end1.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[19] = loadimage("pics/story/end2.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[20] = loadimage("pics/story/end3.bmp")))
		clean_exit(data, (char*)SDL_GetError());
}

void			load_skybox(t_data *data)
{
	if (!(data->surface[8] = loadimage("pics/skybox/skybox_2.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[9] = loadimage("pics/skybox/skybox_3.bmp")))
		clean_exit(data, (char*)SDL_GetError());
}

void			loadmedia(t_data *data)
{
	if (!(data->surface[0] = loadimage("pics/bluestone.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[1] = loadimage("pics/greystone.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[2] = loadimage("pics/mossy.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[3] = loadimage("pics/tile2.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[4] = loadimage("pics/wood.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[5] = loadimage("pics/redbrick.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[6] = loadimage("pics/keydoor.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	if (!(data->surface[7] = loadimage("pics/glass.bmp")))
		clean_exit(data, (char*)SDL_GetError());
	load_skybox(data);
	load_menu(data);
	load_media_hud_1(data);
}
