/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:54:04 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:56:19 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short	count_enemies(t_data *data)
{
	short		count;
	t_object	*iterator;

	count = 0;
	if (data->obj)
	{
		rollback_object(&data->obj);
		iterator = data->obj;
		while (iterator)
		{
			if (iterator->obj_type == 0
					|| iterator->obj_type == 1
					|| iterator->obj_type == 2)
				count++;
			iterator = iterator->next;
		}
	}
	return (count);
}
