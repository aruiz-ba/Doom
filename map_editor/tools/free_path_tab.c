/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:22:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 19:19:38 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			free_path_tab(char **path_tab)
{
	short		i;

	i = -1;
	while (++i < 26)
		if (path_tab[i])
			free(path_tab[i]);
	free(path_tab);
}
