/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 00:01:28 by suddin            #+#    #+#             */
/*   Updated: 2017/05/03 06:22:50 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strresize(char *str, size_t size)
{
	char *tmp;

	tmp = ft_strdup(str);
	free(str);
	str = ft_strnew(size);
	if (ft_strlen(tmp) > size)
		ft_strncpy(str, tmp, size);
	else
		ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}
