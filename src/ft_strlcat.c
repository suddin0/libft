/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 23:07:34 by suddin            #+#    #+#             */
/*   Updated: 2017/05/01 23:44:40 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, char const *src, size_t size)
{
	char		*tab;
	char const	*cpy;
	size_t		n;
	size_t		len;

	tab = dst;
	cpy = (char *)src;
	n = size;
	while (n-- != 0 && *tab)
		tab++;
	len = tab - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(cpy));
	while (*cpy)
	{
		if (n != 1)
		{
			*tab++ = *cpy;
			n--;
		}
		cpy++;
	}
	*tab = '\0';
	return (len + (cpy - src));
}
