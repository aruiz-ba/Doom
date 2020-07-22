/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:32:36 by jmoucach          #+#    #+#             */
/*   Updated: 2020/04/17 17:45:54 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void		free_objects(t_data *data)
{
	t_object	*stock;

	if (data->obj)
	{
		rollback_object(&data->obj);
		while (data->obj)
		{
			stock = data->obj;
			data->obj = data->obj->next;
			free(stock);
			if (data->obj)
				data->obj->prev = NULL;
		}
		data->obj = NULL;
	}
}

static void	free_surf_and_sprites(t_data *data)
{
	int	i;

	if (data->surface && (i = -1))
	{
		while (++i < 21)
			if (data->surface[i])
				SDL_FreeSurface(data->surface[i]);
		free(data->surface);
	}
	if (data->sprites)
	{
		i = -1;
		while (++i < 33)
			if (data->sprites[i])
				SDL_DestroyTexture(data->sprites[i]);
		free(data->sprites);
	}
	if (data->obj_sprite)
	{
		i = -1;
		while (++i < 44)
			if (data->obj_sprite[i].surf)
				SDL_FreeSurface(data->obj_sprite[i].surf);
		free(data->obj_sprite);
	}
}

static void	free_hud(t_data *data)
{
	if (data->hud.hud_texture)
		SDL_DestroyTexture(data->hud.hud_texture);
	if (data->hud.face_texture)
		SDL_DestroyTexture(data->hud.face_texture);
	if (data->hud.hp_text)
		SDL_DestroyTexture(data->hud.hp_text);
	if (data->hud.armor_text)
		SDL_DestroyTexture(data->hud.armor_text);
	if (data->hud.bullets_text)
		SDL_DestroyTexture(data->hud.bullets_text);
	if (data->hud.shells_text)
		SDL_DestroyTexture(data->hud.shells_text);
	if (data->hud.cells_text)
		SDL_DestroyTexture(data->hud.cells_text);
	if (data->hud.ammo_text)
		SDL_DestroyTexture(data->hud.ammo_text);
	if (data->hud.hud_texture)
		SDL_DestroyTexture(data->hud.infinite_text);
}

static void	free_self_alloc_structs(t_data *data)
{
	if (data->zbuffer)
		free(data->zbuffer);
	if (data->e_zbuffer)
		free(data->e_zbuffer);
	if (data->pixels)
		free(data->pixels);
}

void		clean_exit(t_data *data, char *err)
{
	if (err)
		ft_putendl_fd(err, 2);
	free_maps(data);
	delete_cur_map(data);
	free_surf_and_sprites(data);
	free_hud(data);
	free_objects(data);
	free_self_alloc_structs(data);
	if (data->texture)
		SDL_DestroyTexture(data->texture);
	if (data->renderer)
		SDL_DestroyRenderer(data->renderer);
	if (data->window)
		SDL_DestroyWindow(data->window);
	if (data->hud.font)
		TTF_CloseFont(data->hud.font);
	if (TTF_WasInit())
		TTF_Quit();
	if (SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO)
		SDL_Quit();
	exit(err ? EXIT_FAILURE : EXIT_SUCCESS);
}
