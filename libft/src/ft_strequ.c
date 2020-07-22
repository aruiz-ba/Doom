/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:58:10 by acostaz           #+#    #+#             */
/*   Updated: 2019/08/19 15:40:49 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	i;

	if (s1 != NULL && s2 != NULL)
	{
		i = -1;
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		while (s1[++i] != '\0')
			if (s1[i] != s2[i])
				return (0);
		return (1);
	}
	return (0);
}
