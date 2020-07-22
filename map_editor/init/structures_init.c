/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:32:31 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 17:54:41 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

int			ft_sdl_init(t_fdf *ptr, char *name)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_error_fd((char *)SDL_GetError(), 2));
	if (TTF_Init() < 0)
		return (ft_error_fd((char *)TTF_GetError(), 2));
	if (!(ptr->window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0)))
		return (ft_error_fd((char *)SDL_GetError(), 2));
	if (!(ptr->renderer = SDL_CreateRenderer(ptr->window, -1, 0)))
		return (ft_error_fd((char *)SDL_GetError(), 2));
	if (!(ptr->texture = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * 26)))
		return (0);
	return (1);
}

t_fdf		*ft_ptr_init(char *name)
{
	t_fdf	*ptr;

	if (!(ptr = malloc(sizeof(t_fdf))))
		return (NULL);
	if (!(ptr->pixels = (Uint32*)malloc(sizeof(Uint32) * (WIDTH * HEIGHT))))
	{
		free(ptr);
		return (NULL);
	}
	if (!(ft_sdl_init(ptr, NAME)))
	{
		free(ptr->pixels);
		free(ptr);
		return (NULL);
	}
	ft_bzero(ptr->pixels, (WIDTH * HEIGHT * sizeof(Uint32)));
	nullify_textures(ptr);
	loadmedia(ptr);
	ptr->map_name = name;
	ptr->height = HEIGHT;
	ptr->color = ft_hexa_to_sdl(LIGHT_BLUE);
	return (ptr);
}

int			get_light_ceiling(t_map *map, t_line *list)
{
	int		value;

	value = ft_atoi(&list->str[0]);
	if (value < 0 || value > 3)
		return (0);
	map->light_ceiling = value;
	return (1);
}

t_map		*ft_map_init(t_line *list)
{
	t_map	*map;

	if (!(map = ft_map_copy(list)))
		return (NULL);
	if (get_light_ceiling(map, list) == 0)
		return (NULL);
	map->base_gap = ft_gap(map);
	ft_origin(map);
	map->endx = map->ox + ((map->x - 1) * map->base_gap);
	map->endy = map->oy + ((map->y - 1) * map->base_gap);
	return (map);
}
