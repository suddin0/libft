/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:40:42 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 09:50:31 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_EXTRA_H
# define FT_PRINTF_EXTRA_H

# define P_BUFF_SIZE 4096

typedef long int				t_lint;
typedef long long int			t_llint;
typedef intmax_t				t_jint;
typedef size_t					t_zint;
typedef ptrdiff_t				t_tint;
typedef unsigned int			t_uint;
typedef unsigned long int		t_ulint;
typedef unsigned long long int	t_ullint;
typedef unsigned char			t_uchar;
typedef uintmax_t				t_ujint;
typedef size_t					t_uzint;
typedef ptrdiff_t				t_utint;

typedef struct	s_pdata
{
	t_uchar	data[P_BUFF_SIZE + 1];
	size_t	data_len;
	size_t	len;
	int		flags;
	long	tstart;
	long	tend;
}				t_pdata;

typedef struct	s_pflag
{
	char	left_just;
	char	num_sign;
	char	space;
	char	num_type;
	char	zero;
	char	comma;
	char	width;
	int		width_wild;
	int32_t	width_val;
	char	precis;
	int		precis_wild;
	int32_t	precis_val;
	int		length;
	char	flag;
	char	flag_arg;
	int		flag_arg_val;
	int		flag_sign;
	int		nstart;
}				t_pflag;

typedef struct	s_ppnt
{
	int		i;
	int		count;
	int		flag1;
	int		start;
	void	(*(func[26]))(t_pdata *print, t_pflag *flags, va_list args);
}				t_ppnt;

#endif
