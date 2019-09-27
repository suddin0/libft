/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:12:32 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 21:12:34 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

/*
** The following function searches a reference to the given char and retern
** the address where the char was found. It was created to not use `ft_strchr`
** because `ft_strchr` didn't seems to handle a `NULL` parameter as we need in
** this situation.
*/

char	*optchr(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
