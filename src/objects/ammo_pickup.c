/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo_pickup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:54:04 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:56:19 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short	cell_pickup(t_data *data, t_object **obj)
{
	int		id_stock;

	data->p.cells += 50;
	if (data->p.cells > 100)
		data->p.cells = 100;
	id_stock = (*obj)->id_key;
	*obj = (*obj)->next;
	remove_object(&(data->obj), id_stock);
	return (1);
}

short	shell_pickup(t_data *data, t_object **obj)
{
	int		id_stock;

	data->p.shells += 10;
	if (data->p.shells > 20)
		data->p.shells = 20;
	id_stock = (*obj)->id_key;
	*obj = (*obj)->next;
	remove_object(&(data->obj), id_stock);
	return (1);
}

short	bullet_pickup(t_data *data, t_object **obj)
{
	int		id_stock;

	data->p.bullets += 50;
	if (data->p.bullets > 200)
		data->p.bullets = 200;
	id_stock = (*obj)->id_key;
	*obj = (*obj)->next;
	remove_object(&(data->obj), id_stock);
	return (1);
}
