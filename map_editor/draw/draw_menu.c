/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:41:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 17:15:26 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_print_rectangle(t_fdf *img, t_pt pt, int w, int h)
{
	t_pt			pt_a;
	t_pt			pt_b;
	t_pt			pt_c;
	t_pt			pt_d;
	int				colour;

	colour = WHITE;
	pt_a = coord_to_pt(pt.x, pt.y);
	pt_b = coord_to_pt(pt.x + w, pt.y);
	pt_c = coord_to_pt(pt.x + w, pt.y + h);
	pt_d = coord_to_pt(pt.x, pt.y + h);
	if ((pt.x == 1117 || pt.x == 1118 || pt.x == 1277 || pt.x == 1278) && \
		(pt.y == 597 || pt.y == 598))
		colour = GREEN;
	if (((pt.x == 1197 || pt.x == 1198) && (pt.y == 597 || pt.y == 598)) || \
		((pt.x == 1117 || pt.x == 1118) && (pt.y == 677 || pt.y == 678)))
		colour = RED;
	draw_line(pt_a, pt_b, img->pixels, colour);
	draw_line(pt_b, pt_c, img->pixels, colour);
	draw_line(pt_c, pt_d, img->pixels, colour);
	draw_line(pt_d, pt_a, img->pixels, colour);
}

void			draw_menu_squares(t_fdf *img)
{
	int			i;
	t_pt		pt;

	i = 0;
	while (++i <= 22)
	{
		pt.x = 1120 + (((i - 1) % 3) * 80) - 1;
		pt.y = 120 + (((i - 1) / 3) * 80) - 1;
		ft_print_rectangle(img, pt, 70 + 2, 70 + 2);
	}
}

void			ft_print_pressed_skybutton(t_fdf *img, t_mouse *mous)
{
	t_pt		start;

	start.x = 1120 + (((mous->mtime + 18) % 3) * 80) - 3;
	start.y = 120 + (((mous->mtime + 18) / 3) * 80) - 3;
	ft_print_rectangle(img, start, 76, 76);
	start.x = 1120 + (((mous->mtime + 18) % 3) * 80) - 2;
	start.y = 120 + (((mous->mtime + 18) / 3) * 80) - 2;
	ft_print_rectangle(img, start, 74, 74);
	start.x = 1120 + (((mous->mceiling + 20) % 3) * 80) - 3;
	start.y = 120 + (((mous->mceiling + 20) / 3) * 80) - 3;
	ft_print_rectangle(img, start, 76, 76);
	start.x = 1120 + (((mous->mceiling + 20) % 3) * 80) - 2;
	start.y = 120 + (((mous->mceiling + 20) / 3) * 80) - 2;
	ft_print_rectangle(img, start, 74, 74);
}

void			ft_print_pressed_button(t_fdf *img, t_mouse *mous)
{
	t_pt		start;

	if (mous->loop == -1)
		return ;
	if (mous->loop == 0)
	{
		start = coord_to_pt(1119, 759);
		ft_print_rectangle(img, start, 201, 98);
		start = coord_to_pt(1118, 758);
		ft_print_rectangle(img, start, 203, 100);
	}
	else
	{
		start.x = 1120 + (((mous->loop - 1) % 3) * 80) - 3;
		start.y = 120 + (((mous->loop - 1) / 3) * 80) - 3;
		ft_print_rectangle(img, start, 76, 76);
		start.x = 1120 + (((mous->loop - 1) % 3) * 80) - 2;
		start.y = 120 + (((mous->loop - 1) / 3) * 80) - 2;
		ft_print_rectangle(img, start, 74, 74);
	}
	ft_print_pressed_skybutton(img, mous);
}
