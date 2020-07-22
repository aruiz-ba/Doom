/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:51:49 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:39:51 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			print_map(t_map map)
{
	int			i;
	int			j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			ft_putnbr(map.map[i][j]);
			ft_putstr(",\t");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

static void		add_one_item(t_data *data, t_point coords, int type, int *o_num)
{
	addback_object(&(data->obj), new_object(*o_num, type,
				(t_d_point){coords.x + 0.5,
				coords.y + 0.5}));
	data->cur_map.map[coords.x][coords.y] = 0;
	(*o_num)++;
}

static void		item_selection(t_data *data, t_point coords, char c, int *o_num)
{
	if (c == 'O')
		add_one_item(data, coords, 3, o_num);
	else if (c == 'B')
		add_one_item(data, coords, 4, o_num);
	else if (c == 'S')
		add_one_item(data, coords, 5, o_num);
	else if (c == 'C')
		add_one_item(data, coords, 6, o_num);
	else if (c == 'H')
		add_one_item(data, coords, 7, o_num);
	else if (c == 'A')
		add_one_item(data, coords, 8, o_num);
	else if (c == 'K')
		add_one_item(data, coords, 9, o_num);
	else if (c == 'E')
		add_one_item(data, coords, 0, o_num);
	else if (c == 'L')
		add_one_item(data, coords, 1, o_num);
	else if (c == 'D')
		add_one_item(data, coords, 2, o_num);
}

void			fill_raw_map(t_data *data, char *str, short id)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->maps[id].height)
	{
		j = -1;
		while (++j < data->maps[id].width)
			data->maps[id].map[i][j] =
				str[j * 2 + i * 2 * data->maps[id].width];
	}
}

void			fill_map(t_data *data, t_map map)
{
	int			i;
	int			j;
	int			o_num;

	i = -1;
	o_num = 0;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			if (map.map[i][j] == 'P')
			{
				data->p.pos.x = i + 0.5;
				data->p.pos.y = j + 0.5;
				data->cur_map.map[i][j] = 0;
			}
			else if (map.map[i][j] >= '0' && map.map[i][j] <= '8')
			{
				data->cur_map.map[i][j] = map.map[i][j] - '0';
			}
			else
				item_selection(data, (t_point){i, j}, map.map[i][j], &o_num);
		}
	}
}
