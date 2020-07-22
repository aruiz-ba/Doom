/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:58:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/11 11:16:00 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		ft_draw_empty_map(int width, int height, int fd)
{
	int		w;
	int		h;

	h = 0;
	w = -1;
	ft_putendl_fd("2,", fd);
	while (++w < width - 1)
		ft_putstr_fd("1,", fd);
	ft_putstr_fd("1\n", fd);
	while (++h < height - 1)
	{
		w = 0;
		ft_putstr_fd("1,", fd);
		while (++w < width - 1)
			ft_putstr_fd("0,", fd);
		ft_putstr_fd("1\n", fd);
	}
	w = -1;
	while (++w < width - 1)
		ft_putstr_fd("1,", fd);
	ft_putstr_fd("1\n", fd);
}

int			ft_open_existing_map(char *map_name)
{
	int		fd;

	fd = 0;
	if ((fd = open(map_name, O_DIRECTORY) > 0))
	{
		close(fd);
		fd = 0;
	}
	else
		fd = open(map_name, O_RDWR | O_NOFOLLOW);
	return (fd);
}

int			ft_create_map(char *map_name, char *width, char *height)
{
	int		fd;
	int		h;
	int		w;

	w = ft_atoi(width);
	h = ft_atoi(height);
	if (ft_strcmp(&map_name[ft_strlen(map_name) - 5], ".doom") != 0)
		return (ft_error_fd("map name must end with '.doom'", 2));
	if ((fd = open(map_name, O_RDONLY | O_NOFOLLOW)) > 0)
		return (ft_error_fd("Map already exists, remove the size params", 2));
	if ((h <= 2 || w <= 2 || h >= 50 || w >= 50))
		return (ft_error_fd("Dimensions should be > 2 and < 50", 2));
	if ((fd = open(map_name, O_CREAT | O_NOFOLLOW | O_WRONLY, 0666)) <= 0)
		return (ft_error_fd("Unable to create file", 2));
	ft_draw_empty_map(w, h, fd);
	ft_putendl("Map created successfully");
	return (fd);
}

int			ft_check_file(char *file)
{
	int		fd;

	fd = 0;
	if (ft_strcmp(&file[ft_strlen(file) - 5], ".doom") != 0)
		return (ft_error_fd("map name must end with '.doom'", 2));
	if ((fd = open(file, O_DIRECTORY) > 0))
	{
		close(fd);
		fd = 0;
	}
	else
		fd = open(file, O_RDONLY | O_NOFOLLOW);
	return (fd);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc == 4)
		return (ft_create_map(argv[1], argv[2], argv[3]));
	else if (argc == 2)
	{
		if ((fd = ft_check_file(argv[1])) <= 0)
			return (ft_error_fd("Invalid file format", 2));
	}
	else
	{
		ft_putendl_fd("usage\tfor existing map: ./map_editor existing_map", 2);
		ft_putendl_fd("\tfor new map: ./map_editor new_map width height", 2);
		return (0);
	}
	if (!(map = ft_parser(fd)))
		return (ft_error_fd("Invalid map", 2));
	else
		ft_fdf(map, argv[1]);
	return (0);
}
