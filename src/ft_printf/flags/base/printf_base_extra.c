/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:45:02 by suddin            #+#    #+#             */
/*   Updated: 2018/01/27 13:09:00 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		get_num_base(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	else if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'b' || c == 'B')
		return (2);
	return (0);
}

int		cus_num_intlen(t_ullint dec, int base)
{
	int	i;

	i = 0;
	if (dec == 0)
		return (1);
	while (dec > 0)
	{
		i++;
		dec /= base;
	}
	return (i);
}

int		cus_uintlen(t_llint dec, int base)
{
	int	i;

	i = 0;
	if (dec == 0)
		return (1);
	while (dec > 0)
	{
		i++;
		dec /= base;
	}
	return (i);
}

void	set_num_base(t_pdata *print, t_ullint dec, t_uchar base, t_uchar cp)
{
	char	num[33];
	int		i;

	i = 0;
	ft_memset(num, 0, 33);
	if (dec == 0)
		num[i++] = '0';
	if (cp == 0)
		while (dec > 0)
		{
			num[i++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[dec % base];
			dec /= base;
		}
	else
		while (dec > 0)
		{
			num[i++] = "0123456789abcdefghijklmnopqrstuvwzyz"[dec % base];
			dec /= base;
		}
	ft_strrev(num);
	data_man(print, (t_uchar *)num, 0, i);
}
