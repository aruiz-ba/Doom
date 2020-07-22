/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:51:49 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:39:51 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			delete_cur_map(t_data *data)
{
	int			i;

	i = -1;
	if (data->cur_map.map)
	{
		while (++i < data->cur_map.height)
			if (data->cur_map.map[i])
				free(data->cur_map.map[i]);
		free(data->cur_map.map);
		data->cur_map.map = NULL;
	}
}

int				alloc_cur_map(t_data *data, t_map map)
{
	int			i;

	if (!(data->cur_map.map = (int**)malloc(sizeof(int*) * map.height)))
		return (0);
	i = -1;
	while (++i < map.height)
		if (!(data->cur_map.map[i] = (int*)malloc(sizeof(int) * map.width)))
		{
			while (--i >= 0)
				free(data->cur_map.map[i]);
			free(data->cur_map.map);
			return (0);
		}
	return (1);
}

int				copy_cur_map(t_data *data)
{
	int			m;

	m = data->menu_sel;
	if (!alloc_cur_map(data, data->maps[m]))
		return (0);
	data->cur_map.width = data->maps[m].width;
	data->cur_map.height = data->maps[m].height;
	return (1);
}
