/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:34:21 by acostaz           #+#    #+#             */
/*   Updated: 2018/12/01 17:14:22 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	if (lst == NULL)
		return (NULL);
	if (lst != NULL)
	{
		new = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		lst = lst->next;
		first = new;
	}
	while (lst != NULL)
	{
		new->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		lst = lst->next;
		new = new->next;
	}
	return (first);
}
