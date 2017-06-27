/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 02:28:43 by suddin            #+#    #+#             */
/*   Updated: 2017/05/03 06:27:07 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrem(char *str, int from, int len)
{
	char *tmp;

	tmp = ft_strnew(ft_strlen(str) - len);
	ft_strncpy(tmp, str, from);
	ft_strcat(tmp, (str + (from + len)));
	ft_bzero(str, ft_strlen(str));
	ft_strcpy(str, tmp);
	return (str);
}
