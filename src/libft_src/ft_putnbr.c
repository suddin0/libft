/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 05:02:25 by suddin            #+#    #+#             */
/*   Updated: 2019/08/07 00:04:58 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	char			s[FT_INT_MIN_LEN + 1];
	int				i;

	if (n >= 0 && n < 10)
	{
		n += '0';
		write(FT_STDOUT_FD, &(n), 1);
	}
	else if (n == INT_MIN)
		write(FT_STDOUT_FD, "-2147483648", FT_INT_MIN_LEN);
	else
	{
		s[FT_INT_MIN_LEN] = (unsigned int)n >> (FT_INT_SIZE_BIT - 1);
		i = FT_INT_MIN_LEN - 1;
		if (n < 0)
			n = -n;
		while (n)
		{
			s[i--] = (n % 10) + 48;
			n /= 10;
		}
		s[i] = '-';
		i -= s[FT_INT_MIN_LEN];
		write(FT_STDOUT_FD, &(s[i + 1]), (FT_INT_MIN_LEN - i) - 1);
	}
}
