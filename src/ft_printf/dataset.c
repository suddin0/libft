/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:56:12 by suddin            #+#    #+#             */
/*   Updated: 2018/02/01 09:59:37 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	p_data_flush(t_pdata *print)
{
	write(1, print->data, print->data_len);
	print->data[0] = '\0';
	print->data_len = 0;
}

void		dataset(t_pdata *print, t_uchar c, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		if (print->data_len == P_BUFF_SIZE)
			p_data_flush(print);
		print->data[print->data_len] = c;
		(print->len)++;
		(print->data_len)++;
		i++;
	}
}
