/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:40:42 by suddin            #+#    #+#             */
/*   Updated: 2019/08/07 00:13:40 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_EXTRA_H
# define FT_PRINTF_EXTRA_H

# ifndef FT_STDIN_FD
#  define FT_STDIN_FD 0
# endif

# ifndef FT_STDOUT_FD
#  define FT_STDOUT_FD 1
# endif

# ifndef FT_STDERR_FD
#  define FT_STDERR_FD 2
# endif

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

/*
	`s_printf_internal_option` is used in printf_internal. In this structure
	you specify the how your printf behave.
*/

typedef struct	s_printf_internal_option
{
	t_uchar		*buff;
	size_t		buff_size;
	ssize_t		fd;
	char		ret_on_full;
}				t_piopt;

/*
	`s_pdata` is used to store printf internal data such as the buffer where
	printf stores the data, the File Descriptor to write to, a pointer to where
	printf is parsing.

	data		:	The buffer where printf stores data to write later.

	data_size	:	Value indicating how much data `data` (buffer) can contain.
					In other word the `BUFF_SIZE`.

	data_len	:	The count of data stored in the buffer (later used to
					determin if buffer is full and initialized to `0`).

	len			:	The count of `ALL` data stored in the buffer.

	flags		:	Counts the last treated arguments from Variadict List so
					later functions loop over the that point and continue
					treating the next one.

	tstart		:	Used to indicate the `store function` (data_man) where the
					string starts at so store function treate the string from
					there.

	tend		:	Used to indicate the `store function` where the string
					starts at so store function treate the string from there.

	fd			:	The file descriptor where data will be writen,
	ret_on_full :	Return if buffer is full (ccontains 0 OR 1)

*/

typedef struct	s_pdata
{
	// t_uchar	data[P_BUFF_SIZE + 1];
	t_uchar	*data;
	ssize_t	data_size;
	ssize_t	data_len;
	ssize_t	len;
	int		flags;
	long	tstart;
	long	tend;
	ssize_t	fd;
	char	ret_on_full;
}				t_pdata;

/*
	s_pflag is used to represent and store information about a particular format
	that is parsing. It stores all possible aspect of any `format`
*/

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

/*
	s_ppnt exists because of 42 norm as in some places we need more then 5
	variables and more then 4 function parameters, the following structure helps
	us overcome this obstavls.

	It also contain a `function table` which contains all function used for
	formating a strung.
*/

typedef struct	s_ppnt
{
	int		i;
	int		count;
	int		flag1;
	int		start;
	void	(*(func[26]))(t_pdata *print, t_pflag *flags, va_list args);
}				t_ppnt;

#endif
