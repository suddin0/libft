/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 05:02:25 by suddin            #+#    #+#             */
/*   Updated: 2017/05/01 23:17:24 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	char			s[ft_intlen(n) + 1];
	int				i;
	long			k;

	k = n;
	i = (k < 0) ? ft_intlen(k) : ft_intlen(k) - 1;
	ft_bzero(&s, ft_intlen(n) + 1);
	if (k < 0)
	{
		s[0] = '-';
		i--;
		k *= -1;
	}
	else if (k == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (k > 0)
	{
		s[i] = (k % 10) + 48;
		k /= 10;
		i--;
	}
	ft_putstr(s);
}
