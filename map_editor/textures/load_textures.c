/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:22:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 19:19:38 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

SDL_Texture		*loadimage(char *path, t_fdf *img)
{
	SDL_Surface *loadedsurface;
	SDL_Texture	*texture;

	loadedsurface = SDL_LoadBMP(path);
	if (!loadedsurface)
	{
		ft_putendl_fd(SDL_GetError(), 2);
		return (NULL);
	}
	if (!(texture = SDL_CreateTextureFromSurface(img->renderer, loadedsurface)))
	{
		SDL_FreeSurface(loadedsurface);
		ft_clean_exit(img, (char *)SDL_GetError);
	}
	SDL_FreeSurface(loadedsurface);
	return (texture);
}

short			fill_path_tab_2(char **path_tab)
{
	if (!(path_tab[13] = ft_strdup("sprites/shells_button.bmp")))
		return (0);
	if (!(path_tab[14] = ft_strdup("sprites/bullets_button.bmp")))
		return (0);
	if (!(path_tab[15] = ft_strdup("sprites/cell_button.bmp")))
		return (0);
	if (!(path_tab[16] = ft_strdup("sprites/health_button.bmp")))
		return (0);
	if (!(path_tab[17] = ft_strdup("sprites/key_button.bmp")))
		return (0);
	if (!(path_tab[18] = ft_strdup("sprites/armor_button.bmp")))
		return (0);
	if (!(path_tab[19] = ft_strdup("sprites/ceiling_on.bmp")))
		return (0);
	if (!(path_tab[20] = ft_strdup("sprites/ceiling_off.bmp")))
		return (0);
	if (!(path_tab[21] = ft_strdup("sprites/day_mode.bmp")))
		return (0);
	if (!(path_tab[22] = ft_strdup("sprites/night_mode.bmp")))
		return (0);
	if (!(path_tab[23] = ft_strdup("sprites/delete.bmp")))
		return (0);
	if (!(path_tab[24] = ft_strdup("sprites/save.bmp")))
		return (0);
	return (1);
}

short			fill_path_tab(char **path_tab)
{
	if (!(path_tab[1] = ft_strdup("pics/bluestone.bmp")))
		return (0);
	if (!(path_tab[2] = ft_strdup("pics/greystone.bmp")))
		return (0);
	if (!(path_tab[3] = ft_strdup("pics/mossy.bmp")))
		return (0);
	if (!(path_tab[4] = ft_strdup("pics/tile2.bmp")))
		return (0);
	if (!(path_tab[5] = ft_strdup("pics/wood.bmp")))
		return (0);
	if (!(path_tab[6] = ft_strdup("pics/redbrick.bmp")))
		return (0);
	if (!(path_tab[7] = ft_strdup("sprites/doom_guy_face.bmp")))
		return (0);
	if (!(path_tab[8] = ft_strdup("sprites/enemy_face.bmp")))
		return (0);
	if (!(path_tab[9] = ft_strdup("sprites/soul_button.bmp")))
		return (0);
	if (!(path_tab[10] = ft_strdup("sprites/boss_button.bmp")))
		return (0);
	if (!(path_tab[11] = ft_strdup("pics/keydoor.bmp")))
		return (0);
	if (!(path_tab[12] = ft_strdup("pics/glass.bmp")))
		return (0);
	return (fill_path_tab_2(path_tab));
}

char			**path_to_textures(void)
{
	char		**path_tab;
	short		i;

	if (!(path_tab = malloc(sizeof(char *) * 26)))
		return (NULL);
	i = -1;
	while (++i < 26)
		path_tab[i] = NULL;
	if (!fill_path_tab(path_tab))
	{
		free_path_tab(path_tab);
		return (NULL);
	}
	return (path_tab);
}

short			loadmedia(t_fdf *img)
{
	int			i;
	char		**path_tab;

	i = 0;
	if (!(path_tab = path_to_textures()))
		ft_clean_exit(img, "Error allocating texture paths");
	img->texture[0] = NULL;
	while (++i <= 24)
	{
		img->texture[i] = loadimage(path_tab[i], img);
		if (!img->texture[i])
		{
			free_path_tab(path_tab);
			ft_clean_exit(img, "Could not load all textures");
			return (0);
		}
	}
	free_path_tab(path_tab);
	return (1);
}
