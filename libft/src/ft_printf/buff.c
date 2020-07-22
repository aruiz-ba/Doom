/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:25:45 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/19 11:38:01 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	init_buff(t_buff *buff)
{
	ft_bzero(buff->buff, BUFF_SIZE_P);
	buff->i = 0;
	buff->count = 0;
}

void	print_full_buff(t_buff *buff)
{
	write(1, buff->buff, BUFF_SIZE_P);
	ft_bzero(buff->buff, BUFF_SIZE_P);
	buff->count++;
	buff->i = 0;
}

void	fill_buff(t_buff *buffer, char c)
{
	if (buffer->i == BUFF_SIZE_P)
		print_full_buff(buffer);
	buffer->buff[buffer->i] = c;
	buffer->i++;
}
