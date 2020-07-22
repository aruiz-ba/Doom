/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:07:20 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/22 17:28:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;
	int		len;

	if (!(s == NULL))
	{
		i = -1;
		len = ft_strlen(s);
		if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (++i < len)
			res[i] = f(s[i]);
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
