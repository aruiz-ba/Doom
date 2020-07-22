/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_media_hud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:50:16 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 16:51:44 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

SDL_Texture		*loadimage_hud(t_data *data, char *path)
{
	SDL_Surface *loadedsurface;
	SDL_Texture *loadedtexture;

	loadedsurface = SDL_LoadBMP(path);
	if (!loadedsurface)
		return (NULL);
	if (!(loadedtexture = SDL_CreateTextureFromSurface(data->renderer,
		loadedsurface)))
		return (NULL);
	SDL_FreeSurface(loadedsurface);
	return (loadedtexture);
}

void			load_media_hud_3(t_data *data)
{
	if ((!(data->sprites[22] = loadimage_hud(data,
					"sprites/weapons/minigun_1.bmp")))
	|| (!(data->sprites[23] = loadimage_hud(data,
					"sprites/weapons/minigun_2.bmp")))
	|| (!(data->sprites[24] = loadimage_hud(data,
					"sprites/weapons/bfg_firing_1.bmp")))
	|| (!(data->sprites[25] = loadimage_hud(data,
					"sprites/weapons/bfg_firing_2.bmp")))
	|| (!(data->sprites[26] = loadimage_hud(data,
					"sprites/weapons/bfg_1.bmp")))
	|| (!(data->sprites[27] = loadimage_hud(data,
					"sprites/weapons/bfg_2.bmp")))
	|| (!(data->sprites[28] = loadimage_hud(data,
					"sprites/weapons/bfg_3.bmp")))
	|| (!(data->sprites[29] = loadimage_hud(data,
					"sprites/weapons/plasma_1.bmp")))
	|| (!(data->sprites[30] = loadimage_hud(data,
					"sprites/weapons/plasma_2.bmp")))
	|| (!(data->sprites[31] = loadimage_hud(data,
					"sprites/weapons/plasma_3.bmp")))
	|| (!(data->sprites[32] = loadimage_hud(data,
					"sprites/weapons/plasma_4.bmp"))))
		clean_exit(data, (char*)SDL_GetError());
}

void			load_media_hud_2(t_data *data)
{
	if ((!(data->sprites[11] = loadimage_hud(data,
					"sprites/weapons/handgun_1.bmp")))
	|| (!(data->sprites[12] = loadimage_hud(data,
					"sprites/weapons/handgun_2.bmp")))
	|| (!(data->sprites[13] = loadimage_hud(data,
					"sprites/weapons/handgun_3.bmp")))
	|| (!(data->sprites[14] = loadimage_hud(data,
					"sprites/weapons/handgun_4.bmp")))
	|| (!(data->sprites[15] = loadimage_hud(data,
					"sprites/weapons/handgun_5.bmp")))
	|| (!(data->sprites[16] = loadimage_hud(data,
					"sprites/weapons/chainsaw_1.bmp")))
	|| (!(data->sprites[17] = loadimage_hud(data,
					"sprites/weapons/chainsaw_2.bmp")))
	|| (!(data->sprites[18] = loadimage_hud(data,
					"sprites/weapons/chainsaw_3.bmp")))
	|| (!(data->sprites[19] = loadimage_hud(data,
					"sprites/weapons/chainsaw_4.bmp")))
	|| (!(data->sprites[20] = loadimage_hud(data,
					"sprites/weapons/minigun_firing_1.bmp")))
	|| (!(data->sprites[21] = loadimage_hud(data,
					"sprites/weapons/minigun_firing_2.bmp"))))
		clean_exit(data, (char*)SDL_GetError());
	load_media_hud_3(data);
}

void			load_media_hud_1(t_data *data)
{
	if ((!(data->sprites[0] = loadimage_hud(data,
						"sprites/weapons/hand_1.bmp")))
	|| (!(data->sprites[1] = loadimage_hud(data,
				"sprites/weapons/knuckle_1.bmp")))
	|| (!(data->sprites[2] = loadimage_hud(data,
				"sprites/weapons/knuckle_2.bmp")))
	|| (!(data->sprites[3] = loadimage_hud(data,
				"sprites/weapons/knuckle_3.bmp")))
	|| (!(data->sprites[4] = loadimage_hud(data,
				"sprites/weapons/shotgun_firing_1.bmp")))
	|| (!(data->sprites[5] = loadimage_hud(data,
				"sprites/weapons/shotgun_firing_2.bmp")))
	|| (!(data->sprites[6] = loadimage_hud(data,
				"sprites/weapons/shotgun_1.bmp")))
	|| (!(data->sprites[7] = loadimage_hud(data,
				"sprites/weapons/shotgun_2.bmp")))
	|| (!(data->sprites[8] = loadimage_hud(data,
				"sprites/weapons/shotgun_3.bmp")))
	|| (!(data->sprites[9] = loadimage_hud(data,
				"sprites/weapons/shotgun_4.bmp")))
	|| (!(data->sprites[10] = loadimage_hud(data,
				"sprites/weapons/handgun_firing.bmp"))))
		clean_exit(data, (char*)SDL_GetError());
	load_media_hud_2(data);
}
