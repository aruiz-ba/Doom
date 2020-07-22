/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:19:22 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/20 15:38:12 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (tofind[0] == '\0')
		return ((char*)str);
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == tofind[0])
		{
			j = 1;
			while (str[i + j] == tofind[j] && (i + j) < len &&
					tofind[j] != '\0')
				j++;
			if (tofind[j] == '\0')
				return ((char*)str + i);
		}
		i++;
	}
	return (0);
}
