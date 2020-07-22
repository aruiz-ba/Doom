/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:39:30 by jmoucach          #+#    #+#             */
/*   Updated: 2020/02/26 13:13:47 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace(char *str, char find, char replace)
{
	char	*current_pos;

	if (!str)
		return (NULL);
	current_pos = ft_strchr(str, find);
	while (current_pos)
	{
		*current_pos = replace;
		current_pos = ft_strchr(current_pos + 1, find);
	}
	return (str);
}
