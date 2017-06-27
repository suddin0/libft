/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 01:47:46 by suddin            #+#    #+#             */
/*   Updated: 2017/05/01 23:21:26 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_itoa(int n)
{
	char			*s;
	int				i;
	long			k;

	k = n;
	s = ft_strnew(ft_intlen(n));
	if (s == NULL)
		return (NULL);
	i = (k < 0) ? ft_intlen(k) : ft_intlen(k) - 1;
	if (k < 0)
	{
		s[0] = '-';
		i--;
		k *= -1;
	}
	else if (k == 0)
		s[0] = '0';
	while (k > 0)
	{
		s[i] = (k % 10) + 48;
		k /= 10;
		i--;
	}
	return (s);
}
