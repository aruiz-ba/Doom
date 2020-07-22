/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:23:58 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/29 19:28:49 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*newspace;
	size_t	i;

	i = -1;
	if (!(newspace = (char*)malloc(size)))
		return (NULL);
	while (++i < size)
		newspace[i] = 0;
	return (newspace);
}
