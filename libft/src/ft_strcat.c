/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:37:49 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:41:38 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(dest);
	while (src[++i] != '\0')
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
