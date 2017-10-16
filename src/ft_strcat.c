/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 23:07:04 by suddin            #+#    #+#             */
/*   Updated: 2017/04/20 04:58:20 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0')
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}
