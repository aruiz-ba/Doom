/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:53:06 by sjulliot          #+#    #+#             */
/*   Updated: 2019/09/25 14:53:24 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strndup(char *src, size_t len)
{
	char	*res;

	if (!src || !(res = (char*)malloc(len)))
		return (NULL);
	return (ft_strncpy(res, src, len));
}
