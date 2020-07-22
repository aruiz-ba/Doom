/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 01:16:20 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 12:56:39 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static uint8_t	objects_are_neighbours(t_object *obj1, t_object *obj2)
{
	if (!obj1 || !obj2)
		return (0);
	if (obj1->next)
		if (obj1->next->id_key == obj2->id_key)
			return (1);
	if (obj2->next)
		if (obj2->next->id_key == obj1->id_key)
			return (1);
	return (0);
}

static void		swap_neighbour2(t_object *obj1, t_object *obj2)
{
	t_object	*tmp;

	if (obj1->next->id_key == obj2->id_key)
	{
		tmp = obj2->next;
		obj2->next = obj1;
		obj1->next = tmp;
		tmp = obj1->prev;
		obj1->prev = obj2;
		obj2->prev = tmp;
	}
	else
	{
		tmp = obj1->next;
		obj1->next = obj2;
		obj2->next = tmp;
		tmp = obj2->prev;
		obj2->prev = obj1;
		obj1->prev = tmp;
	}
}

static void		swap_neighbour(t_object **head, t_object *obj1, t_object *obj2)
{
	if (obj1->prev != NULL && obj1->prev->id_key != obj2->id_key)
		obj1->prev->next = obj2;
	else if (obj1->prev == NULL)
		*head = obj2;
	if (obj1->next != NULL && obj1->next->id_key != obj2->id_key)
		obj1->next->prev = obj2;
	if (obj2->prev != NULL && obj2->prev->id_key != obj1->id_key)
		obj2->prev->next = obj1;
	else if (obj2->prev == NULL)
		*head = obj1;
	if (obj2->next != NULL && obj2->next->id_key != obj1->id_key)
		obj2->next->prev = obj1;
	swap_neighbour2(obj1, obj2);
}

static void		swap_non_neighbour(t_object **head, t_object *obj1,
	t_object *obj2)
{
	t_object	*tmp;

	if (obj1->prev != NULL)
		obj1->prev->next = obj2;
	else
		*head = obj2;
	if (obj1->next != NULL)
		obj1->next->prev = obj2;
	if (obj2->prev != NULL)
		obj2->prev->next = obj1;
	else
		*head = obj1;
	if (obj2->next != NULL)
		obj2->next->prev = obj1;
	tmp = obj2->next;
	obj2->next = obj1->next;
	obj1->next = tmp;
	tmp = obj2->prev;
	obj2->prev = obj1->prev;
	obj1->prev = tmp;
}

void			swap_objects(t_object **head, t_object *obj1, t_object *obj2)
{
	if (!obj1 || !obj2 || !head || !(*head))
		return ;
	if (obj1->id_key == obj2->id_key)
		return ;
	if (objects_are_neighbours(obj1, obj2))
		swap_neighbour(head, obj1, obj2);
	else
		swap_non_neighbour(head, obj1, obj2);
}
