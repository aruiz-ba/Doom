/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:42:04 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/19 14:23:01 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int				rotate_left(char *buf)
{
	int			endl;

	if (!buf)
		return (0);
	endl = 0;
	while (buf[endl] != '\0' && buf[endl] != '\n')
		endl++;
	if (buf[endl] != '\0')
	{
		endl++;
		ft_strncpy(buf, buf + endl, ft_strlen(buf + endl) + 1);
	}
	else
		ft_strclr(buf);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	int			i;
	char		*buf;
	static char	*reads;
	char		*tmp;

	if (read(fd, reads, 0) || !line || !(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	reads = reads ? reads : ft_strnew(0);
	i = rotate_left(reads);
	ret = -1;
	while (!ft_strchr(reads, '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		tmp = reads;
		reads = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	while (reads[i] != '\0' && reads[i] != '\n')
		i++;
	*line = ft_strncpy(ft_strnew(i), reads, i);
	if (reads && !ret)
		ft_strdel(&reads);
	ft_strdel(&buf);
	return (ret || **line);
}
