/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:39:08 by acostaz           #+#    #+#             */
/*   Updated: 2018/11/30 12:49:58 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*mark;

	i = -1;
	mark = 0;
	while (str[++i] != '\0')
		if (str[i] == c)
			mark = (char*)str + i;
	if (c == 0)
		mark = (char*)str + i;
	return (mark);
}
