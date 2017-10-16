/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 20:22:05 by suddin            #+#    #+#             */
/*   Updated: 2017/04/24 09:49:00 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *a;
	t_list *b;

	if (!lst)
		return (NULL);
	b = f(lst);
	a = b;
	if (b == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		b->next = f(lst);
		if (b->next == NULL)
			return (NULL);
		b = b->next;
	}
	return (a);
}
