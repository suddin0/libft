/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 02:45:44 by suddin            #+#    #+#             */
/*   Updated: 2017/12/04 02:51:06 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Thiis is a strdup but instead of returning the allocated space
** Where the src was copied, it returns the lenth of src. This function
** is useful when you need to know the lenth of the char you are
** duplicating in the same time, it saves you the process power, line
** and time by not repeating the same things
*/

size_t	ft_strdupl(char **dest, char *src)
{
	size_t len;

	if (!*dest || !src)
		return (0);
	len = ft_strlen(src);
	*dest = ft_strnew(len);
	ft_strcpy(*dest, src);
	return (len);
}
