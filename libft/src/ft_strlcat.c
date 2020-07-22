/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:57:50 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:44:13 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		len;
	char		*d;
	const char	*s;

	s = src;
	d = dest;
	i = 0;
	while (i++ < size && *d != '\0')
		d++;
	len = d - dest;
	i = size - len;
	if (i == 0)
		return (size + ft_strlen(s));
	while (*s != '\0')
	{
		if (i > 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (len + (s - src));
}
