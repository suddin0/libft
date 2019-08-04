/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:23:08 by suddin            #+#    #+#             */
/*   Updated: 2018/01/27 14:46:32 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	cus_iintlen(long long n, int comma)
{
	int		i;
	int		com;
	char	count;

	i = (n <= 0) ? 1 : 0;
	com = 0;
	count = 0;
	if (comma > 0)
		while (n != 0 && count++ > -1)
		{
			n /= 10;
			if (count == 3 && (count = 0) > -1)
				com++;
			i++;
		}
	else
		while (n != 0)
		{
			n /= 10;
			i++;
		}
	return (i + com);
}

int	cus_uuintlen(unsigned long long n, int comma)
{
	int		i;
	int		com;
	char	count;

	i = (n <= 0) ? 1 : 0;
	com = 0;
	count = 0;
	if (comma > 0)
		while (n != 0 && count++ > -1)
		{
			n /= 10;
			if (count == 3 && (count = 0) > -1)
				com++;
			i++;
		}
	else
		while (n != 0)
		{
			n /= 10;
			i++;
		}
	return (i + com);
}
