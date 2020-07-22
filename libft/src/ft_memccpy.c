/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:13:14 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/29 19:28:58 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dest;

	i = 0;
	src = (unsigned char*)s;
	dest = (unsigned char*)d;
	while (i < n && src[i] != (unsigned char)c)
	{
		dest[i] = src[i];
		i++;
	}
	if (s + i && src[i] == (unsigned char)c && i != n)
	{
		dest[i] = (unsigned char)c;
		return (d + i + 1);
	}
	return (NULL);
}
