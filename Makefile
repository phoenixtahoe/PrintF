# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:12:14 by pdavid            #+#    #+#              #
#    Updated: 2018/12/07 23:23:52 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_isdigit.c ft_bzero.c ft_memset.c ft_strcat.c ft_strcpy.c ft_itoa.c ft_ltoa.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsub.c get.c print_char.c print_int.c print_wchar.c print_wstr.c print_str.c spec.c printf.c

OBJECTS = $(SRC:.c=.o)

SRCDIR = ./src/

SRCS	= $(addprefix $(SRCDIR), $(SRC))

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): 
		gcc $(FLAGS) -c $(SRCS)
		ar rcs $(NAME) $(OBJECTS)
		ranlib $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean clean all