/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:04:21 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:27:45 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	int		i;
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		i = -1;
		if (!(str = (char*)malloc(sizeof(char) * (l1 + l2 + 1))))
			return (NULL);
		while (++i < l1)
			str[i] = s1[i];
		i = -1;
		while (++i < l2)
			str[l1 + i] = s2[i];
		str[l1 + l2] = '\0';
		return (str);
	}
	return (NULL);
}
