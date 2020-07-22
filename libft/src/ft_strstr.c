/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:39:19 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:50:08 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *tofind)
{
	int i;
	int j;

	i = -1;
	if (tofind[0] == '\0')
		return ((char*)str);
	while (str[++i] != '\0')
	{
		if (str[i] == tofind[0])
		{
			j = 1;
			while (str[i + j] == tofind[j] && tofind[j] != '\0')
				j++;
			if (tofind[j] == '\0')
				return ((char*)str + i);
		}
	}
	return (0);
}
