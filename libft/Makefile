# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 23:14:53 by alkaram           #+#    #+#              #
#    Updated: 2023/12/20 17:55:15 by alkaram          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
NAME = libft.a
ARFLAGS = rc
CFLAGS = -Wall -Werror -Wextra
SRCFILES = 	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_strjoin.c \
			ft_itoa.c \
			ft_split.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
		
OBJFILES = ${SRCFILES:.c=.o}
.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME) : $(OBJFILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)
all : $(NAME)
fclean : clean
	rm -rf $(NAME)
clean :
	rm -rf $(OBJFILES)
re : fclean $(NAME)
.PHONY: all clean fclean re
