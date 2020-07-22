/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:41:22 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:29:09 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	int				len;

	if (!(s == NULL))
	{
		i = -1;
		len = ft_strlen(s);
		if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s[++i] != '\0')
			res[i] = f(i, s[i]);
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
