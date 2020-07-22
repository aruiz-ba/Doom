/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:41:11 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 16:35:23 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	check_doors(t_data *data)
{
	t_point	pos;

	pos.x = (int)(data->p.pos.x);
	pos.y = (int)(data->p.pos.y);
	if (data->p.key > 0)
	{
		if (data->cur_map.map[pos.x + 1][pos.y] == 7)
			pos.x++;
		else if (data->cur_map.map[pos.x - 1][pos.y] == 7)
			pos.x--;
		else if (data->cur_map.map[pos.x][pos.y + 1] == 7)
			pos.y++;
		else if (data->cur_map.map[pos.x][pos.y - 1] == 7)
			pos.y--;
		else
			return ;
		data->cur_map.map[pos.x][pos.y] = 0;
		data->p.key--;
	}
}
