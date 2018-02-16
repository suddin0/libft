/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:27:49 by suddin            #+#    #+#             */
/*   Updated: 2018/01/27 14:46:30 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include "ft_printf_extra.h"

int		ft_printf(const char *restrict format, ...);
int		is_flag(t_uchar c);
void	data_man(t_pdata *print, t_uchar *src, long start, long end);
void	dataset(t_pdata *print, t_uchar c, size_t n);
int		flag_man(t_pdata *print, t_ppnt *temp, char *str, va_list args);
int		check_flag(t_pflag *flag, char *str, int start, int end);
int		check_width(t_pflag *flag, char *str, int start, int end);
int		check_precis(t_pflag *flag, char *str, int start, int end);
int		format_verif(t_pflag *flag, char *str, int start, int end);
t_llint	*arg_llint(int *read, int arg_num, t_pdata *print, va_list args);
t_uint	*arg_uint(int *read, int arg_num, t_pdata *print, va_list args);
t_ullint*arg_ullint (int *read, int arg_num, t_pdata *print, va_list args);
char	*arg_str(int *read, int arg_num, t_pdata *print, va_list args);
wchar_t	*arg_wchars(int *read, int arg_num, t_pdata *print, va_list args);
wchar_t	*arg_wcharc(int *read, int arg_num, t_pdata *print, va_list args);
void	*arg_void(int *read, int arg_num, t_pdata *print, va_list args);
void	*field_proc(t_pdata *print, t_pflag *flag, va_list args,\
void	*func(int *read, int arg_num, t_pdata *print, va_list args));
int		multi_verif(t_pflag *flag, int *val, void *f_val, int arg_n);
int		verif_f1(t_pflag *flag, int *val, int *read);
int		verif_f2(t_pflag *flag, int *val, int *read);
int		verif_f3(t_pflag *flag, int *val, int arg_n);
int		verif_l1(t_pflag *flag, int *val, int *read, int32_t *f_val);
int		verif_l2(t_pflag *flag, int *val, int *read, int32_t *f_val);
int		verif_l3(t_pflag *flag, int *val, int arg_n, int32_t *f_val);
int		get_next_int(int *read, int arg_num, t_pdata *print, va_list args);
void	simple_sort	(int *array, int len);
void	hier_man(t_pdata *print, t_pflag *flag, int *array, int *val_tmp);
void	printf_string(t_pdata *print, t_pflag *flags, va_list args);
void	printf_number(t_pdata *print, t_pflag *flags, va_list args);
void	printf_char(t_pdata *print, t_pflag *flags, va_list args);
int		cus_iintlen(long long n, int comma);
int		cus_uuintlen(unsigned long long n, int comma);
void	printf_int(t_pdata *print, t_pflag *flags, va_list args);
void	printf_uint(t_pdata *print, t_pflag *flags, va_list args);
void	printf_uuint(t_pdata *print, t_pflag *flags, va_list args);
void	printf_lint(t_pdata *print, t_pflag *flags, va_list args);
void	printf_percent(t_pdata *print, t_pflag *flags, va_list args);
int		get_num_base(char c);
int		cus_num_intlen(t_ullint dec, int base);
void	set_num_base(t_pdata *print, t_ullint dec, t_uchar base, t_uchar cp);
void	printf_base(t_pdata *print, t_pflag *flags, va_list args);
int		cus_uintlen(t_llint dec, int base);
void	printf_ubase(t_pdata *print, t_pflag *flags, va_list args);
void	printf_pointer(t_pdata *print, t_pflag *flags, va_list args);
void	printf_wcharc(t_pdata *print, t_pflag *flags, va_list args);
void	printf_wchars(t_pdata *print, t_pflag *flags, va_list args);
void	w_to_char(wchar_t c, unsigned char *s, int *i);

#endif
