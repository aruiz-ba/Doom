/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:15:24 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:39:52 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short			parse_char(char *str)
{
	int			i;
	int			p_num;

	i = -1;
	p_num = 0;
	while (str[++i])
	{
		if (str[i] == 'P')
			p_num++;
		else if (str[i] != '0' && str[i] != '1' && str[i] != '2'
				&& str[i] != '3' && str[i] != '4' && str[i] != '5'
				&& str[i] != '6' && str[i] != '7' && str[i] != '8'
				&& str[i] != ',' && str[i] != 'E' && str[i] != 'S'
				&& str[i] != 'C' && str[i] != 'H' && str[i] != 'A'
				&& str[i] != 'K' && str[i] != 'L' && str[i] != 'D'
				&& str[i] != 'B')
		{
			ft_putstr_fd("Invalid map data", 2);
			return (0);
		}
	}
	if (p_num != 1)
		ft_putstr_fd("Invalid number of player", 2);
	return (p_num == 1 ? 1 : 0);
}

void			parse_boudaries(char *str, t_data *data, short id)
{
	int			x;
	int			y;
	int			bot_loc;

	y = 0;
	while (y < data->maps[id].height)
	{
		if (str[2 * (y * data->maps[id].width)] < '1'
			|| str[2 * (y * data->maps[id].width)] > '6'
			|| str[2 * ((y + 1) * data->maps[id].width - 1)] < '1'
			|| str[2 * ((y + 1) * data->maps[id].width - 1)] > '6')
			clean_exit(data, "Incomplete boundaries");
		y++;
	}
	x = -1;
	while (++x < data->maps[id].width)
	{
		bot_loc = 2 * (x + (data->maps[id].height - 1) * data->maps[id].width);
		if (str[2 * x] < '1' || str[2 * x] > '6'
			|| str[bot_loc] < '1'
			|| str[bot_loc] > '6')
			clean_exit(data, "Incomplete boundaries");
	}
}

void			parse_map(t_data *data, char *str, short id)
{
	if (!(parse_char(str)))
		clean_exit(data, "");
	parse_boudaries(str, data, id);
}
