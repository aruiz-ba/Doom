/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:06:14 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 19:15:53 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_print_blocks(t_pt pt, int map_value, t_fdf *img, int size)
{
	SDL_Rect	rect;
	SDL_Texture	*texture;

	rect = (SDL_Rect){pt.x + 1, pt.y + 1, size - 2, size - 2};
	texture = img->texture[map_value];
	SDL_RenderCopy(img->renderer, texture, NULL, &rect);
}

void			print_buttons_delete_and_save(t_fdf *img)
{
	SDL_Rect	rect;
	SDL_Texture	*texture;

	rect = (SDL_Rect){1120, 650 + 110, 200, 97};
	texture = img->texture[23];
	SDL_RenderCopy(img->renderer, texture, NULL, &rect);
	rect = (SDL_Rect){1120, 650 + 115 + 97, 200, 97};
	texture = img->texture[24];
	SDL_RenderCopy(img->renderer, texture, NULL, &rect);
}

void			draw_menu_textures(t_fdf *img)
{
	int			i;
	t_pt		pt;

	i = 0;
	while (++i <= 22)
	{
		pt.x = 1120 + (((i - 1) % 3) * 80);
		pt.y = 120 + (((i - 1) / 3) * 80);
		ft_print_blocks(pt, i, img, 70);
	}
	print_buttons_delete_and_save(img);
}

void			ft_parse_and_print_textures(t_fdf *img)
{
	int			x;
	int			y;
	t_pt		pt;

	y = -1;
	while (++y < img->map->y)
	{
		x = -1;
		while (++x < img->map->x)
		{
			pt.y = (y * img->map->base_gap) + img->map->oy;
			pt.x = (x * img->map->base_gap) + img->map->ox;
			ft_print_blocks(pt, img->map->map[y][x],
			img, img->map->base_gap);
		}
	}
}
