/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 07:36:15 by suddin            #+#    #+#             */
/*   Updated: 2018/01/23 08:14:34 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	w_to_char(wchar_t c, unsigned char *s, int *i)
{
	*i = 1;
	if (c < (1 << 7))
		*s++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*s++ = (unsigned char)((c >> 6) | 0xC0);
		*s++ = (unsigned char)((c & 0x3F) | 0x80);
		*i = 2;
	}
	else if (c < (1 << 16))
	{
		*s++ = (unsigned char)(((c >> 12)) | 0xE0);
		*s++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*s++ = (unsigned char)((c & 0x3F) | 0x80);
		*i = 3;
	}
	else if (c < (1 << 21))
	{
		*s++ = (unsigned char)(((c >> 18)) | 0xF0);
		*s++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*s++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*s++ = (unsigned char)((c & 0x3F) | 0x80);
		*i = 4;
	}
	*s = 0;
}
