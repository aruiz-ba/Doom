/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:04:47 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 19:46:29 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		ft_free_map(t_map *map)
{
	int		i;

	i = -1;
	if (map)
	{
		while (++i < map->y)
		{
			if (map->map[i])
				free(map->map[i]);
		}
		if (map->map)
			free(map->map);
		free(map);
	}
}

void		ft_free_fdf(t_fdf *fdf)
{
	ft_free_map(fdf->map);
	free(fdf);
}

void		ft_free_line(t_line *list)
{
	t_line	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->str);
		free(tmp);
	}
	free(list);
}

static void	ft_free_textures(t_fdf *img)
{
	int		i;

	i = 0;
	if (img->texture)
	{
		while (++i < 21)
		{
			if (img->texture[i] != NULL)
				SDL_DestroyTexture(img->texture[i]);
			img->texture[i] = NULL;
		}
		free(img->texture);
	}
}

void		ft_clean_exit(t_fdf *img, char *err)
{
	if (err)
		ft_putendl_fd(err, 2);
	if (img)
		ft_free_textures(img);
	if (img && img->grid != NULL)
		SDL_DestroyTexture(img->grid);
	if (img && img->renderer != NULL)
		SDL_DestroyRenderer(img->renderer);
	if (img && img->pixels != NULL)
		free(img->pixels);
	if (img && img->window)
		SDL_DestroyWindow(img->window);
	if (TTF_WasInit())
		TTF_Quit();
	if (SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO)
		SDL_Quit();
	if (err)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
