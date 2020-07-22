/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_incoming_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:37:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 19:47:48 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

t_line			*ft_newline(void const *content)
{
	static int	i = 0;
	t_line		*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->str = ft_strdup(content);
	new->x = 0;
	new->next = NULL;
	new->prev = NULL;
	new->y = i;
	i++;
	return (new);
}

static void		add_new_line(char *linetmp, t_line **line)
{
	t_line		*tmp;
	t_line		*tmp2;

	tmp = *line;
	while (tmp->next)
		tmp = tmp->next;
	tmp2 = ft_newline(linetmp);
	tmp2->prev = tmp;
	tmp->next = tmp2;
}

static short	check_first_line(char *line)
{
	if (ft_strcmp(line, "0,") && ft_strcmp(line, "1,")
			&& ft_strcmp(line, "2,") && ft_strcmp(line, "3,"))
		return (0);
	return (1);
}

t_line			*ft_list_alloc(int fd)
{
	char		*linetmp;
	t_line		*line;

	line = NULL;
	while (get_next_line(fd, &linetmp) > 0)
	{
		if (line == NULL)
		{
			if (!check_first_line(linetmp) || !(line = ft_newline(linetmp)))
			{
				free(linetmp);
				return (NULL);
			}
		}
		else
			add_new_line(linetmp, &line);
		free(linetmp);
	}
	free(linetmp);
	return (line);
}
