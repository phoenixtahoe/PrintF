# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:12:14 by pdavid            #+#    #+#              #
#    Updated: 2018/12/11 12:09:43 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_ultoa.c ft_strlower.c ft_isdigit.c ft_bzero.c ft_memset.c ft_strcat.c ft_strcpy.c ft_itoa.c ft_ltoa.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsub.c get.c print_char.c print_int.c print_wchar.c print_wstr.c print_str.c spec.c printf.c print_base.c

OBJECTS = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = obj

SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
OBJ	= $(addprefix $(OBJDIR)/, $(OBJECTS))

NAME = libftprintf.a

HEADER = -I includes

FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		mkdir -p $(OBJDIR)
		gcc $(FLAGS) $(HEADER) $< -o $@

$(NAME): $(OBJ)
		ar rcs $@ $^
		ranlib $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all