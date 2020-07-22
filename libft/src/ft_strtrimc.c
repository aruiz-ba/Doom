/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:39:11 by jmoucach          #+#    #+#             */
/*   Updated: 2020/02/26 13:14:18 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char *s, char c)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	j = 0;
	a = 0;
	if (!s)
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[j])
		j++;
	j = j - 1;
	while (s[j] == c && j > i)
		j--;
	while (i <= j)
		s[a++] = s[i++];
	s[a] = '\0';
	return (s);
}
