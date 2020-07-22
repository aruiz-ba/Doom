/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:20:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 18:49:29 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

int			ft_conform_char(char c)
{
	if (ft_isdigit(c) == 1
			|| c == 'P'
			|| c == 'E'
			|| c == 'L'
			|| c == 'D'
			|| c == 'K'
			|| c == 'S'
			|| c == 'B'
			|| c == 'C'
			|| c == 'A'
			|| c == 'H')
		return (1);
	return (0);
}

/*
** This function transforms every wrong value we have in the mp (cf function
**above) into ',' AND keeps only the last digit of numbers above 10 (replaces
**the other digits with ',')
*/

char		*ft_conform_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_conform_char(str[i]) == 1 &&
					(str[i + 1] == ',' || str[i + 1] == '\0'))
				|| str[i] == ',')
			i++;
		else
		{
			str[i] = ',';
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
