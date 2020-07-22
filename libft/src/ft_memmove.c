/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:25:47 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:18:03 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src < dest)
		while (len-- > 0)
			((unsigned char*)dest)[len] = ((unsigned char*)src)[len];
	else
		while (++i < len)
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	return (dest);
}
