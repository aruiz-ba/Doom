/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:13:47 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:34:06 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_w(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		front;
	int		back;
	char	*res;

	if (s)
	{
		len = 0;
		while (ft_is_w(s[len]))
			len++;
		if ((front = len) && s[len] == '\0')
			return (ft_strdup(""));
		while (s[len++] != '\0')
			if (!(ft_is_w(s[len - 1])) && (ft_is_w(s[len]) || s[len] == '\0'))
				back = len - 1;
		len = back - front + 1;
		if (!(res = (char*)malloc(len + 1)))
			return (NULL);
		back = -1;
		while (++back < len)
			res[back] = s[back + front];
		res[len] = '\0';
		return (res);
	}
	return (NULL);
}
