/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_key_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:45:00 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 22:29:26 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

int		ft_mouse_init(t_mouse *mous)
{
	mous->click = 0;
	mous->loop = 1;
	return (1);
}

int		ft_key_init(t_key *key)
{
	key->up = 0;
	key->down = 0;
	key->left = 0;
	key->right = 0;
	key->zoom_in = 0;
	key->zoom_out = 0;
	return (1);
}
