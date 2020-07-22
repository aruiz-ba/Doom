/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:07:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

int				which_thread(t_data *data)
{
	int		res;

	res = 0;
	while (res < NB_THREAD && pthread_self() != data->thread[res])
		res++;
	return (res);
}

static void		*threaded_casting(void *d)
{
	t_data		*data;

	data = (t_data*)d;
	raycasting(data);
	cast_objects(data);
	windowcasting(data);
	pthread_exit(0);
}

void			thread_center(t_data *data)
{
	short		i;

	i = -1;
	while (++i < NB_THREAD)
		if (pthread_create(&data->thread[i], NULL, threaded_casting, data))
			clean_exit(data, "pthread_create error");
	i = -1;
	while (++i < NB_THREAD)
		if (pthread_join(data->thread[i], NULL))
			clean_exit(data, "pthread_join error");
}
