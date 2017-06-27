# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suddin <suddin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 02:38:27 by suddin            #+#    #+#              #
#    Updated: 2017/05/18 01:03:09 by suddin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC  = 	ft_bzero.c		\
		ft_memset.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstnew.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_strrev.c		\
		ft_intlen.c		\
		ft_abs.c		\
		ft_strresize.c	\
		ft_strrem.c		\
		ft_sqrt.c		\
		ft_putnbrendl.c	\
		ft_chrindex.c	\
		ft_chrindexi.c	\
		ft_strjoini.c	\
		ft_strchri.c


TOO := $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Werror -Wextra -Wall $(SRC)
	@ar rc $(NAME) $(TOO)
	@ranlib $(NAME)

clean:
	@rm -f $(TOO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
