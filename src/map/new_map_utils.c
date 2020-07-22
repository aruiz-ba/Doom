/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:46:23 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/10 14:12:28 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short			count_lines_and_col(t_data *data, char *str, short id)
{
	t_parse		p;

	p.i = -1;
	while (++p.i < (int)ft_strlen(str))
	{
		p.col = data->maps[id].width;
		data->maps[id].width = 0;
		p.tmp = 0;
		while (str[p.i] && str[p.i] != '\n')
		{
			if (p.tmp == 1 && str[p.i] != ',')
				return (0);
			if (p.tmp == 1 && str[p.i] == ',')
				p.tmp = 0;
			if (p.tmp == 0 && str[p.i] != ',')
				data->maps[id].width++;
			if (p.tmp == 0 && str[p.i] != ',')
				p.tmp = 1;
			p.i++;
		}
		if (data->maps[id].width != p.col && p.col != 0)
			return (0);
		data->maps[id].height++;
	}
	return (1);
}

short			map_too_big(char *name)
{
	int			fd;
	int			i;
	int			len;
	int			objects;
	char		*line;

	len = 0;
	objects = 0;
	fd = open(name, O_NOCTTY | O_RDONLY | O_NOFOLLOW | O_NONBLOCK);
	while (get_next_line(fd, &line) > 0)
	{
		len += ft_strlen(line);
		i = -1;
		while (line[++i] != '\0')
			if (line[i] == 'E' || line[i] == 'L' || line[i] == 'D'
					|| line[i] == 'K' || line[i] == 'S' || line[i] == 'B'
					|| line[i] == 'C')
				objects++;
		free(line);
		if (len > 5000 || objects > 100)
			return (1);
	}
	close(fd);
	free(line);
	return (0);
}
