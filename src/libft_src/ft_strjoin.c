/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:06:08 by suddin            #+#    #+#             */
/*   Updated: 2017/04/24 09:56:02 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *fresh;

	if (!s1 || !s2)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (fresh == NULL)
		return (NULL);
	ft_strcpy(fresh, (char *)s1);
	ft_strcat(fresh, (char *)s2);
	return (fresh);
}
