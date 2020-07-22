/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:39:53 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/25 16:52:32 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	print_one_key(t_data *data, int x, int y)
{
	int		i;
	int		j;
	Uint32	color;

	i = -1;
	while (++i < 60)
	{
		j = -1;
		while (++j < 60)
		{
			color = get_pixel(data->obj_sprite[43].surf, i, j);
			if (color != 0)
				data->pixels[(i + x) + (j + y) * SCREEN_WIDTH] = color;
		}
	}
}

void		display_hud_keys(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->p.key)
	{
		if (i < 5)
			print_one_key(data, SCREEN_WIDTH - (i + 1) * 80 - 1, 10);
		else
			print_one_key(data, SCREEN_WIDTH - (i - 4) * 80 - 1, 90);
	}
}
