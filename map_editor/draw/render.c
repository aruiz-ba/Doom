/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:49:15 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/06 14:34:43 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		initialize_and_write_lines(t_fdf *img, t_mouse *mous)
{
	ft_bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint32));
	ft_print_grid(img);
	if (!img->grid)
	{
		if (!(img->grid = SDL_CreateTexture(img->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH,
		HEIGHT)))
			ft_clean_exit(img, (char *)SDL_GetError());
	}
	draw_menu_squares(img);
	ft_print_pressed_button(img, mous);
}

void		ft_clear_and_render(t_fdf *img, t_mouse *mous)
{
	initialize_and_write_lines(img, mous);
	SDL_UpdateTexture(img->grid, NULL, img->pixels, WIDTH * 4);
	SDL_RenderCopy(img->renderer, img->grid, NULL, NULL);
	ft_parse_and_print_textures(img);
	draw_menu_textures(img);
	SDL_RenderPresent(img->renderer);
	SDL_RenderClear(img->renderer);
}
