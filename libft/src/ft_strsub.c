/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:54:23 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:33:11 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	size_t			index;

	if (s != NULL)
	{
		i = 0;
		index = -1;
		if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (++index < len)
		{
			res[i] = s[i + start];
			i++;
		}
		res[len] = '\0';
		return (res);
	}
	return (NULL);
}
