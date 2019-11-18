/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:27:49 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:18:28 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *restrict format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_snprintf(char *str, size_t size, const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vsprintf(char *str, const char *format, va_list ap);
int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);

#endif
