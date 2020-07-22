/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:02:46 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 19:20:07 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

int				ft_check_equal_length(t_line *line)
{
	int			tmp;
	int			i;

	i = 0;
	while (line->next)
	{
		i++;
		tmp = line->x;
		line = line->next;
		if (tmp != line->x || tmp >= 100 || i >= 99)
			return (0);
	}
	return (1);
}

t_map			*ft_parser(int fd)
{
	t_line		*list;
	t_map		*map;

	list = ft_list_alloc(fd);
	map = ft_map_init(list);
	if (map == NULL || ft_check_equal_length(list->next) == 0)
	{
		if (map)
			ft_free_map(map);
		if (list)
			ft_free_line(list);
		return (NULL);
	}
	ft_free_line(list);
	return (map);
}
