/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_weapon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:15:04 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 14:46:52 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short				use_weapon(t_data *data, short id)
{
	static short	(*use_type[7])(t_data*, short) = {use_knuckle, use_shotgun,
		use_plasma, use_chainsaw, use_handgun, use_bfg, use_minigun};
	short			res;

	if (data->p.is_firing && data->p.selected_weapon != 3)
		data->p.has_fired = 1;
	res = use_type[id](data, data->p.is_firing);
	return (res);
}
