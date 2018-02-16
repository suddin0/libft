/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 07:36:15 by suddin            #+#    #+#             */
/*   Updated: 2018/01/23 08:20:06 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	wchars_len(wchar_t *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] < (1 << 7))
			i++;
		else if (str[count] < (1 << 11))
			i += 2;
		else if (str[count] < (1 << 16))
			i += 3;
		else if (str[count] < (1 << 21))
			i += 4;
		count++;
	}
	return (i);
}

static void	wchar_write(t_pdata *print, wchar_t *str, int len)
{
	unsigned char	s[5];
	int				t;
	int				s_len;
	int				i;

	t = 0;
	s_len = 0;
	i = 0;
	while (t <= len)
	{
		w_to_char(str[i], s, &s_len);
		t += s_len;
		if (t <= len)
			data_man(print, s, 0, s_len);
		else if (t > len)
			return ;
		i++;
	}
}

static int	get_precis(wchar_t *str, int p)
{
	int	i;
	int	size;
	int	cp;

	i = 0;
	size = 0;
	cp = 0;
	while (str[i] && cp < p)
	{
		if (str[i] < (1 << 7))
			size++;
		else if (str[i] < (1 << 11))
			size += 2;
		else if (str[i] < (1 << 16))
			size += 3;
		else if (str[i] < (1 << 21))
			size += 4;
		if (size > p)
			return (cp);
		cp = size;
		i++;
	}
	return (cp);
}

static void	str_data_process(t_pdata *print, t_pflag *flags, wchar_t *str)
{
	int total;
	int to_copy;
	int str_len;
	int a;
	int i;

	a = flags->precis_val;
	str_len = wchars_len(str);
	i = 0;
	to_copy = (a < str_len && a != -1) ? get_precis(str, a) : str_len;
	total = (flags->width_val > to_copy) ? flags->width_val : to_copy;
	a = flags->left_just;
	if (a > 0)
		wchar_write(print, str, to_copy);
	dataset(print, (flags->zero > 0 && a == 0) ? '0' : ' ', total - to_copy);
	i = 0;
	if (flags->left_just <= 0)
		wchar_write(print, str, to_copy);
}

void		printf_wchars(t_pdata *print, t_pflag *flags, va_list args)
{
	wchar_t	*str;

	str = NULL;
	str = (wchar_t *)field_proc(print, flags, args, (void *)arg_wchars);
	if (str == NULL && flags->precis_val > 0 && flags->precis_val < 6)
		str_data_process(print, flags, L"");
	else
		str_data_process(print, flags, (str == NULL) ? L"(null)" : str);
}
