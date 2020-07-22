/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:22:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 19:52:12 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		ft_origin(t_map *map)
{
	map->ox = (1120 - ((map->x) * map->base_gap)) / 2;
	map->oy = (HEIGHT - ((map->y) * map->base_gap)) / 2;
}

int			ft_gap(t_map *map)
{
	int		gap_h;
	int		gap_w;

	gap_h = (HEIGHT * 0.9) / map->y;
	gap_w = (1120 * 0.9) / map->x;
	if (gap_h > gap_w)
		return (gap_w);
	else
		return (gap_h);
}
