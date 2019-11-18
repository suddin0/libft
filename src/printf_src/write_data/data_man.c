/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:28:41 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:21:50 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal_func.h"

static void	p_data_flush(t_pdata *print)
{
	if (print->fd > -1)
		write(print->fd, print->data, print->data_len);
	print->data[0] = '\0';
	print->data_len = 0;
}

void		data_man(t_pdata *print, t_uchar *src, long start, long end)
{
	if (start >= end || (print->ret_on_full && print->len >= print->data_size))
		return ;
	while (start != end)
	{
		if (print->ret_on_full && print->len >= print->data_size)
			break ;
		if (print->data_len == print->data_size)
			p_data_flush(print);
		print->data[print->data_len] = src[start];
		(print->len)++;
		(print->data_len)++;
		start++;
	}
}
