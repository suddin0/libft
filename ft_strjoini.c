/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:06:08 by suddin            #+#    #+#             */
/*   Updated: 2017/05/18 02:20:19 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoini(char const *s1, char const *s2, size_t len)
{
	char *fresh;

	if (!s1 || !s2)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s1) + len + 1);
	if (fresh == NULL)
		return (NULL);
	ft_strcpy(fresh, (char *)s1);
	ft_strncat(fresh, (char *)s2, len);
	return (fresh);
}
