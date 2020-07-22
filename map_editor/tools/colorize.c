/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:56:35 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 19:45:02 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

SDL_Color		ft_hexa_to_sdl(int color)
{
	SDL_Color	col;

	col.b = (color & 0xff);
	col.g = (color & 0xff00) >> 8;
	col.r = (color & 0xff0000) >> 16;
	col.a = 255;
	return (col);
}
