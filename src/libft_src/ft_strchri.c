/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 23:07:08 by suddin            #+#    #+#             */
/*   Updated: 2017/05/18 01:11:52 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchri(const char *s, int c, unsigned int len)
{
	unsigned int	i;
	char			*ss;

	i = 0;
	ss = (char *)s;
	while (i < len && ss[i])
	{
		if (ss[i] == (char)c)
			return (ss + i);
		i++;
	}
	if (ss[i] == (char)c)
		return (ss + i);
	return (NULL);
}
