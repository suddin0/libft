/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 08:41:54 by suddin            #+#    #+#             */
/*   Updated: 2017/05/02 23:58:56 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *fresh;

	if (!s)
		return (NULL);
	fresh = ft_strnew(len);
	if (fresh == NULL)
		return (NULL);
	ft_strncpy(fresh, (char *)(s + (start)), len);
	return (fresh);
}
