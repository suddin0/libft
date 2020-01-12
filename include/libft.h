/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 23:08:34 by suddin            #+#    #+#             */
/*   Updated: 2019/10/16 04:53:06 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

/*
** The following header is used to detect the machine architechure
*/

# include <stdint.h>

# if INTPTR_MAX == INT32_MAX
#  define FT_CHAR_SIZE_BYTE			1
#  define FT_SHORT_SIZE_BYTE		2
#  define FT_INT_SIZE_BYTE			4
#  define FT_LONG_INT_SIZE_BYTE		4
#  define FT_FLOAT_SIZE_BYTE		4
#  define FT_DOUBLE_SIZE_BYTE		8
#  define FT_LONG_DOUBLE_SIZE_BYTE	12

#  define FT_CHAR_SIZE_BIT			8
#  define FT_SHORT_SIZE_BIT			16
#  define FT_INT_SIZE_BIT			32
#  define FT_LONG_INT_SIZE_BIT		32
#  define FT_FLOAT_SIZE_BIT			32
#  define FT_DOUBLE_SIZE_BIT		64
#  define FT_LONG_DOUBLE_SIZE_BIT	96

# elif INTPTR_MAX == INT64_MAX
#  define FT_CHAR_SIZE_BYTE			1
#  define FT_SHORT_SIZE_BYTE		2
#  define FT_INT_SIZE_BYTE			4
#  define FT_LONG_INT_SIZE_BYTE		8
#  define FT_FLOAT_SIZE_BYTE		4
#  define FT_DOUBLE_SIZE_BYTE		8
#  define FT_LONG_DOUBLE_SIZE_BYTE	16

#  define FT_CHAR_SIZE_BIT			8
#  define FT_SHORT_SIZE_BIT			16
#  define FT_INT_SIZE_BIT			32
#  define FT_LONG_INT_SIZE_BIT		64
#  define FT_FLOAT_SIZE_BIT			32
#  define FT_DOUBLE_SIZE_BIT		64
#  define FT_LONG_DOUBLE_SIZE_BIT	128

/*
*  `error` : a compiler macro that stops the compilation (here we stop the
*  compilation conditionally.)
*/

# else
#  error "Architecture is not 32 bit nor 64 bit."
# endif

# define FT_STDIN_FD				0
# define FT_STDOUT_FD				1
# define FT_STDERR_FD				2

/*
**	SHRT_MAX	:	 32767
**	SHRT_MIN	:	–32768
**
**	INT_MAX		:	 2147483647
**	INT_MIN		:	-2147483648
**
**	UINT_MAX	:	 4294967295
**
**	LONG_MAX	:	 9223372036854775807
**	LONG_MIN	:	-9223372036854775808
*/

# define FT_SHRT_MAX_LEN			5
# define FT_SHRT_MIN_LEN			6

# define FT_INT_MAX_LEN				10
# define FT_UINT_MAX_LEN			10
# define FT_INT_MIN_LEN				11

# define FT_LONG_MAX_LEN			19
# define FT_LONG_MIN_LEN			11

/**
* The following define is used to set the mac size of a program name.
* Do not set it to a too short number.
**/

# define MAX_PROGRAM_NAME			1024

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy (void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
size_t			ft_strdupl(char **dest, char *src);
size_t			ft_strlcat(char *dest, char const *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, size_t n);
char			*ft_strnstr(char *str, char *to_find, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(char *str, char *to_find);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putnchar(char c, int n);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_strrev(char *str);
int				ft_intlen(long n);
int				ft_abs(int i);
char			*ft_strresize(char *str, size_t size);
char			*ft_strrem(char *str, int from, int len);
int				ft_sqrt(int nb);
void			ft_putnbrendl(int i);
int				ft_chrindex(char *str, char c);
int				ft_chrindexi(char *str, char c, int len);
char			*ft_strjoini(char const *s1, char const *s2, size_t len);
char			*ft_strchri(const char *s, int c, unsigned int len);

int				set_program_name(char *n_name);
const char		*get_program_name();

#endif
