/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:27:49 by acostaz           #+#    #+#             */
/*   Updated: 2020/02/26 12:49:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short	is_in_frame(t_point pt)
{
	if (pt.x >= 0 && pt.y >= 0 && pt.x < SCREEN_WIDTH && pt.y < SCREEN_HEIGHT)
		return (1);
	return (0);
}
