/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:57:32 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 18:02:10 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

t_object		*new_object(int id, int type, t_d_point pos)
{
	static void	(*get_obj_data[4])(t_object **) = {get_obj_data_0,
		get_obj_data_1, get_obj_data_2, get_obj_data_3};
	t_object	*new;

	new = NULL;
	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	ft_bzero(new, sizeof(t_object));
	new->id_key = id;
	new->obj_type = type;
	new->hp = 10;
	new->pos = pos;
	if (type > 2)
		get_obj_data[0](&new);
	else if (type == 2)
		get_obj_data[3](&new);
	else
		get_obj_data[type + 1](&new);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			addback_object(t_object **head, t_object *new)
{
	t_object	*iterator;

	iterator = NULL;
	if (!head || !new)
		return ;
	if (!(*head))
		*head = new;
	else
	{
		iterator = *head;
		while (iterator->next)
			iterator = iterator->next;
		iterator->next = new;
		new->prev = iterator;
		new->next = NULL;
	}
}

void			rollback_object(t_object **head)
{
	if (head && *head)
		while ((*head)->prev)
			*head = (*head)->prev;
}

void			remove_object(t_object **head, int key)
{
	t_object	*iterator;

	if (!head || !(*head))
		return ;
	iterator = *head;
	while (iterator)
	{
		if (iterator->id_key == key)
		{
			if (iterator->prev == NULL && iterator->next == NULL)
				(*head) = NULL;
			if (iterator->prev)
				iterator->prev->next = iterator->next;
			else
				(*head) = iterator->next;
			if (iterator->next)
				iterator->next->prev = iterator->prev;
			free(iterator);
			return ;
		}
		iterator = iterator->next;
	}
}

void			sort_objects(t_data *data)
{
	t_object	*iterator;

	iterator = data->obj;
	while (iterator->next)
	{
		if (iterator->dist_to_player < iterator->next->dist_to_player)
		{
			swap_objects(&(data->obj), iterator, iterator->next);
			iterator = data->obj;
		}
		iterator = iterator->next;
	}
}
